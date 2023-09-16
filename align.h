#ifndef INC_01_08_TEXT_JUSTIFIER__ALIGN_H_
#define INC_01_08_TEXT_JUSTIFIER__ALIGN_H_

#include <iostream>
#include <string>

enum class Align {
  Left = 0,
  Right,
  Justify,
  Center
};

std::string align(std::istream &in, int width, Align a);

#endif //INC_01_08_TEXT_JUSTIFIER__ALIGN_H_
