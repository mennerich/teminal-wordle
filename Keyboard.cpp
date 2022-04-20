//
// Created by donald on 4/17/22.
//

#include "Keyboard.h"
#include <map>
#include <string>
#include <iostream>

using namespace std;

Keyboard::Keyboard() {
    make_row(0, "qwertyuiop");
    make_row(1, "asdfghjkl");
    make_row(2, "zxcvbnm");
}

void Keyboard::make_row(const int &i, const string &s) {
    map<int, Letter> row;
    for (int j = 0; j < s.size(); j++) {
        row[j] = Letter{s[j], LS_Unknown};
    }
    key_map[i] = row;
}

void Keyboard::print_keyboard() {
    string spacer;
    for (auto &row: key_map) {
        cout << spacer;
        for (auto &letter: row.second) {
            switch (letter.second.letter_state) {
                case LS_Unknown:
                    cout << " " << letter.second.letter << " ";
                    break;
                case LS_Found:
                    cout << "[" << letter.second.letter << "]";
                    break;
                case LS_FoundPlaced:
                    cout << "[" << char(toupper(letter.second.letter)) << "]";
                    break;
                case LS_Removed:
                    cout << "    ";
            }
        }
        spacer.push_back(' ');
        spacer.push_back(' ');
        cout << endl;
    }
}

void Keyboard::update_letter(char c, Letter_State ls) {
    int letter_id;
    int row_id;

    auto row = key_map.begin();
    while (row != key_map.end()) {
        auto letters = row->second.begin();
        while (letters != row->second.end()) {
            if (letters->second.letter == tolower(c)) {
                row_id = row->first;
                letter_id = letters->first;
            }
            letters++;
        }
        ++row;
    }

    Letter_State current_state = key_map[row_id][letter_id].letter_state;
    if (current_state != LS_FoundPlaced) {
        key_map[row_id][letter_id].letter_state = ls;
    }
}

void Keyboard::dump_key_map() {
    for (auto &row: key_map) {
        for (auto &letter: row.second) {
            cout << letter.second.letter << " : " << letter.second.letter_state << endl;
        }
    }
}

Letter_State Keyboard::get_letter_state(char c) {

    auto row = key_map.begin();
    while (row != key_map.end()) {
        auto letters = row->second.begin();
        while (letters != row->second.end()) {
            if (letters->second.letter == tolower(c)) {
                return letters->second.letter_state;
            }
            letters++;
        }
        row++;
    }
}