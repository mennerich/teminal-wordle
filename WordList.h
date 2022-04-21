//
// Created by donald on 4/14/22.
//

#ifndef UNTITLED_WORDLIST_H
#define UNTITLED_WORDLIST_H

#include <map>
#include <vector>
#include <string>
#include "Keyboard.h"

class WordList {
private:
    Keyboard keyboard;
    static std::vector<std::string> solutions;
    static std::vector<std::string> valid_words;
    std::map<int, std::string> guess_results;
    std::string selected_word;
    static void to_upper_case(std::string *);

public:
    WordList();
    static int get_length();
    static bool contains_word(std::string);
    std::string get_selected_word();
    bool guess_selected_word(std::string);
    void process_guess(int guess_num, std::string);
    void print_guess_history();
    void print_keyboard() { keyboard.print_keyboard(); };
};


#endif //UNTITLED_WORDLIST_H
