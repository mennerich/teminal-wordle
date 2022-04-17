//
// Created by donald on 4/17/22.
//

#ifndef UNTITLED_KEYBOARD_H
#define UNTITLED_KEYBOARD_H

#include "letter.h"
#include <map>
#include <string>

class Keyboard {
private:
    std::map<int,std::map<int, Letter>> key_map;
    void make_row(const int&, const std::string&);
public:
    Keyboard();
    void print_keyboard();
};


#endif //UNTITLED_KEYBOARD_H
