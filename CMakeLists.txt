cmake_minimum_required(VERSION 3.23)
project(01_08_text_justifier)

set(CMAKE_CXX_STANDARD 17)

add_executable(01_08_text_justifier main.cpp align.cpp align.h)
add_executable(test test.cpp align.cpp align.h)
