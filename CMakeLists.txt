cmake_minimum_required(VERSION 3.21)
project(tword)

set(CMAKE_CXX_STANDARD 20)

add_executable(tword main.cpp WordList.cpp WordList.h Keyboard.cpp Keyboard.h)
