#include <iostream>
#include <string>
#include <fstream>

#include "align.h"

using namespace std;

int main(int argc, char **argv) {
  int width = 80;
  if (1 < argc) {
    width = stol(argv[1]);
  }

  string result;
  char *filename = nullptr;
  Align a = Align::Left;
  if (2 < argc) {
    filename = argv[2];
    ifstream in{filename};
    if (!in.is_open()) {
      cerr << "Can't read "s << filename << endl;
      return -1;
    }
    if (3 < argc) {
      a = Align{stoi(argv[3])};
    }
    result = align(in, width, a);
  } else {
    result = align(cin, width, a);
  }
  cout << result << endl;

  return 0;
}
