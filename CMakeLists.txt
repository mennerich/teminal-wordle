cmake_minimum_required(VERSION 3.21)
project(terminal-wordle)

set(CMAKE_CXX_STANDARD 20)

add_executable(terminal-wordle main.cpp WordList.cpp WordList.h Keyboard.cpp Keyboard.h letter.h)
