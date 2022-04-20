//
// Created by donald on 4/17/22.
//

#ifndef UNTITLED_KEYBOARD_H
#define UNTITLED_KEYBOARD_H

#include <map>
#include <string>


enum Letter_State {
    LS_Unknown,
    LS_FoundPlaced,
    LS_Found,
    LS_Removed,
    LS_Error
};

struct Letter {
    char letter;
    Letter_State letter_state;
};

class Keyboard {
private:
    std::map<int,std::map<int, Letter>> key_map;
    void make_row(const int&, const std::string&);

public:
    Keyboard();
    void dump_key_map();
    void print_keyboard();
    void update_letter(char, Letter_State);
    Letter_State get_letter_state(char);
};

#endif //UNTITLED_KEYBOARD_H
