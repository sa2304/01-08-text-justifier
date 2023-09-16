/*
The MIT License (MIT)
Copyright © 2023 Anton Schmidt <schmidt.ajax@yandex.ru>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <iostream>
#include <string>
#include <fstream>

#include "align.h"

using namespace std;

Align parseAlign(const string& s) {
  Align a = Align::Left;
  if ("r"s == s) {
    a = Align::Right;
  } else if ("j"s == s) {
    a = Align::Justify;
  } else if ("c"s == s) {
    a = Align::Center;
  }

  return a;
}

void printUsage(const char *app_name) {
  cout << "Usage: "s << app_name << " <text-width> l|r|j|c <filename>"s << endl;
}

int main(int argc, char **argv) {
  if (2 == argc && string{argv[1]} == "--help"s) {
    printUsage(argv[0]);
    return 0;
  }

  int width = 80;
  if (1 < argc) {
    width = stol(argv[1]);
  }

  string result;
  Align a = Align::Left;
  if (2 < argc) {
    a = parseAlign(argv[2]);
  }

  if (3 < argc) {
    char *filename = argv[3];
    ifstream in{filename};
    if (!in.is_open()) {
      cerr << "Can't read "s << filename << endl;
      return -1;
    }
    result = align(in, width, a);
  } else {
    result = align(cin, width, a);
  }
  cout << result << endl;

  return 0;
}
