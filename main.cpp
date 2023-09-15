#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string alignLeft(istream& in, int width) {
  string word, line, result;
  int curr_width = 0;
  while (in >> word) {
    if (curr_width + word.length() < width) {
      line += word + ' ';
      curr_width += word.length() + 1;
    } else {
      result += line + '\n';
      line = word + ' ';
      curr_width = line.size();
    }
  }

  return result;
}

int main(int argc, char** argv) {
  int width = 80;
  if (1 < argc) {
    width = stol(argv[1]);
  }

  string result;
  char *filename = nullptr;
  if (2 < argc) {
    filename = argv[2];
    ifstream in{filename};
    if (!in.is_open()) {
      cerr << "Can't read "s << filename << endl;
      return -1;
    }
    result = alignLeft(in, width);
  } else {
    result = alignLeft(cin, width);
  }
  cout << result << endl;

  return 0;
}
