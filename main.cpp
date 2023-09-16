#include <cassert>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

enum class Align {
  Left = 0,
  Right
};

void appendLine(string &result, const vector<string> &words, int line_curr_width, int width, Align a) {
  if (Align::Right == a) {
    int left_pad = width - line_curr_width;
    if (0 < left_pad) result += string(left_pad, ' ');
  }
  for (int i = 0; i < words.size(); ++i) {
    if (0 < i) result += ' ';
    result += words[i];
  }
  result.push_back('\n');
}

string align(istream &in, int width, Align a) {
  string word, result;
  int line_char_count = 0;
  vector<string> line_words;
  while (in >> word) {
    const int line_curr_width = line_char_count + line_words.size() - 1;
    if (line_curr_width + 1 + word.length() <= width) {
      line_words.push_back(word);
      line_char_count += word.length();
    } else {
      appendLine(result, line_words, line_curr_width, width, a);
      line_words = {word};
      line_char_count = word.length();
    }
  }
  // Append last buffered line
  if (!line_words.empty()) {
    const int line_curr_width = line_char_count + line_words.size() - 1;
    appendLine(result, line_words, line_curr_width, width, a);
  }

  return result;
}

static const string SampleText = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor "
                                 "incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud "
                                 "exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";

void TestLeftAlign20() {
  string expected = "Lorem ipsum dolor\n"
                    "sit amet,\n"
                    "consectetur\n"
                    "adipiscing elit, sed\n"
                    "do eiusmod tempor\n"
                    "incididunt ut labore\n"
                    "et dolore magna\n"
                    "aliqua. Ut enim ad\n"
                    "minim veniam, quis\n"
                    "nostrud exercitation\n"
                    "ullamco laboris nisi\n"
                    "ut aliquip ex ea\n"
                    "commodo consequat.\n";
  stringstream s{SampleText};
  string result = align(s, 20, Align::Left);
  assert(expected == result);
}

void TestLeftAlign80() {
  string expected = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor\n"
                    "incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis\n"
                    "nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\n";
  stringstream s{SampleText};
  string result = align(s, 80, Align::Left);
  assert(expected == result);
}

void TestRightAlign40() {
  string expected = " Lorem ipsum dolor sit amet, consectetur\n"
                    "  adipiscing elit, sed do eiusmod tempor\n"
                    "    incididunt ut labore et dolore magna\n"
                    "   aliqua. Ut enim ad minim veniam, quis\n"
                    "    nostrud exercitation ullamco laboris\n"
                    "nisi ut aliquip ex ea commodo consequat.\n";
  stringstream s{SampleText};
  string result = align(s, 40, Align::Right);
  assert(expected == result);
}

void TestRightAlign25() {
  string expected = "    Lorem ipsum dolor sit\n"
                    "        amet, consectetur\n"
                    "  adipiscing elit, sed do\n"
                    "eiusmod tempor incididunt\n"
                    "ut labore et dolore magna\n"
                    " aliqua. Ut enim ad minim\n"
                    "     veniam, quis nostrud\n"
                    "     exercitation ullamco\n"
                    "  laboris nisi ut aliquip\n"
                    " ex ea commodo consequat.\n";
  stringstream s{SampleText};
  string result = align(s, 25, Align::Right);
  assert(expected == result);
}

int main(int argc, char **argv) {
  TestLeftAlign20();
  TestLeftAlign80();
  TestRightAlign40();
  TestRightAlign25();
  cout << "Tests passed!\n"s;
  return 0;

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
