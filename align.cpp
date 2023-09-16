#include "align.h"

#include <fstream>
#include <vector>

using namespace std;

void appendLine(string &result, const vector<string> &words, int line_char_count, int width, Align a) {
  string separator = " "s;
  int just_sep_remainder = 0;
  const int line_space_count = width - (line_char_count + words.size() - 1);
  if (Align::Right == a && 0 < line_space_count) {
    result += string(line_space_count, ' ');
  } else if (Align::Center == a && 0 < line_space_count) {
    auto pad = std::div(line_space_count, 2);
    result += string(pad.quot + pad.rem, ' ');
  } else if (Align::Justify == a) {
    int space_count = width - line_char_count;
    const int sep_count = words.size() - 1;
    int sep_length = 1;
    if (0 < sep_count) {
      sep_length = space_count / sep_count;
      just_sep_remainder = space_count % sep_count;
      separator = string(sep_length, ' ');
    }
  }
  for (int i = 0; i < words.size(); ++i) {
    if (0 < i) {
      result += separator;
      if (Align::Justify == a && 0 < just_sep_remainder--) {
        result.push_back(' ');
      }
    }
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
      appendLine(result, line_words, line_char_count, width, a);
      line_words = {word};
      line_char_count = word.length();
    }
  }
  // Append last buffered line
  if (!line_words.empty()) {
    const int line_curr_width = line_char_count + line_words.size() - 1;
    appendLine(result, line_words, line_char_count, width, a);
  }

  return result;
}
