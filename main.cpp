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
