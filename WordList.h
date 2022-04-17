//
// Created by donald on 4/14/22.
//

#ifndef UNTITLED_WORDLIST_H
#define UNTITLED_WORDLIST_H

#include <map>
#include <vector>
#include <string>

struct Letter {
    char letter;
    bool guessed;
};

class WordList {
private:
    std::vector<std::string> words;
    std::map<int, std::string> guess_results;
    std::string selected_word;
    void to_upper_case(std::string *);

public:
    WordList();
    int get_length();
    bool contains_word(std::string);
    std::string get_selected_word();
    bool guess_selected_word(std::string);
    void process_guess(int guess_num, std::string);
    void print_guess_history();
};


#endif //UNTITLED_WORDLIST_H
