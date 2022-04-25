cmake_minimum_required(VERSION 3.17)
project(tword)

set(CMAKE_CXX_STANDARD 20)

link_libraries(sqlite3)

add_executable(tword main.cpp WordList.cpp WordList.h Keyboard.cpp Keyboard.h database.cpp database.h main.h)
