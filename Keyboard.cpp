//
// Created by donald on 4/17/22.
//

#include "Keyboard.h"
#include <map>
#include <string>
#include <iostream>

using namespace std;

Keyboard::Keyboard() {

    const string row1 = "qwertyuiop";
    const string row2 = "asdfghjkl";
    const string row3 = "zxcvbnm";

    make_row(0, row1);
    make_row(1, row2);
    make_row(2, row3);

}

void Keyboard::make_row(const int& i, const string& s) {

    map<int, Letter> row;
    for(int j = 0; j < s.size(); j++) {
        row[j] = Letter{s[j], LS_Unknown};
    }
    key_map[i] = row;
}

void Keyboard::print_keyboard() {
    string spacer = "";
    for(auto& row: key_map) {
        cout << spacer;
        for(auto& letter: row.second) {
            cout << letter.second.letter << " ";
        }
        spacer.push_back(' ');
        cout << endl;
    }
}