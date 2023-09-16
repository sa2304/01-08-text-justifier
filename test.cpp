#include <cassert>
#include <sstream>

#include "align.h"

using namespace std;

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

void TestJustify30() {
  string expected = "Lorem  ipsum  dolor  sit amet,\n"
                    "consectetur  adipiscing  elit,\n"
                    "sed    do    eiusmod    tempor\n"
                    "incididunt ut labore et dolore\n"
                    "magna aliqua. Ut enim ad minim\n"
                    "veniam,      quis      nostrud\n"
                    "exercitation  ullamco  laboris\n"
                    "nisi  ut aliquip ex ea commodo\n"
                    "consequat.\n";
  stringstream s{SampleText};
  string result = align(s, 30, Align::Justify);
  assert(expected == result);
}

void TestJustify60() {
  string expected = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed\n"
                    "do  eiusmod  tempor  incididunt  ut  labore  et dolore magna\n"
                    "aliqua.  Ut  enim ad minim veniam, quis nostrud exercitation\n"
                    "ullamco  laboris  nisi  ut  aliquip ex ea commodo consequat.\n";
  stringstream s{SampleText};
  string result = align(s, 60, Align::Justify);
  assert(expected == result);
}

void TestCenter38() {
  string expected = "      Lorem ipsum dolor sit amet,\n"
                    "  consectetur adipiscing elit, sed do\n"
                    "eiusmod tempor incididunt ut labore et\n"
                    " dolore magna aliqua. Ut enim ad minim\n"
                    "   veniam, quis nostrud exercitation\n"
                    " ullamco laboris nisi ut aliquip ex ea\n"
                    "          commodo consequat.\n";
  stringstream s{SampleText};
  string result = align(s, 38, Align::Center);
  assert(expected == result);
}

void TestCenter70() {
  string expected = "    Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do\n"
                    "eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad\n"
                    "    minim veniam, quis nostrud exercitation ullamco laboris nisi ut\n"
                    "                   aliquip ex ea commodo consequat.\n";
  stringstream s{SampleText};
  string result = align(s, 70, Align::Center);
  assert(expected == result);
}

void TestCenter10() {
  string expected = "   Lorem\n"
                    "   ipsum\n"
                    " dolor sit\n"
                    "   amet,\n"
                    "consectetur\n"
                    "adipiscing\n"
                    " elit, sed\n"
                    "do eiusmod\n"
                    "  tempor\n"
                    "incididunt\n"
                    " ut labore\n"
                    " et dolore\n"
                    "   magna\n"
                    "aliqua. Ut\n"
                    "  enim ad\n"
                    "   minim\n"
                    "  veniam,\n"
                    "   quis\n"
                    "  nostrud\n"
                    "exercitation\n"
                    "  ullamco\n"
                    "  laboris\n"
                    "  nisi ut\n"
                    "aliquip ex\n"
                    "ea commodo\n"
                    "consequat.\n";
  stringstream s{SampleText};
  string result = align(s, 10, Align::Center);
  assert(expected == result);
}

int main() {
  TestLeftAlign20();
  TestLeftAlign80();
  TestRightAlign40();
  TestRightAlign25();
  TestJustify30();
  TestJustify60();
  TestCenter38();
  TestCenter70();
  TestCenter10();
  cout << "Tests passed!\n"s;

  return 0;
}