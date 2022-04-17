//
// Created by donald on 4/17/22.
//

#ifndef UNTITLED_LETTER_H
#define UNTITLED_LETTER_H

enum Letter_State {
    LS_Unknown,
    LS_FoundPlaced,
    LS_Found,
    LS_Removed
};

struct Letter {
    char letter;
    Letter_State letter_state;
};

#endif //UNTITLED_LETTER_H
