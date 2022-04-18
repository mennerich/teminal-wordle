//
// Created by donald on 4/14/22.
//

#include "WordList.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

WordList::WordList() {
    ifstream dict("/usr/share/dict/english");
    if (dict.is_open()) {
        string line;
        while (getline(dict, line)) {
            if (line.size() == 5) {
                to_upper_case(&line);
                if (!contains_word(line)) {
                    words.push_back(line);
                }
            }
        }
        dict.close();
    }

    srand((unsigned)time(nullptr ));
    selected_word = words[(rand() % words.size()) + 1];
}

bool WordList::guess_selected_word(std::string guess) {
    to_upper_case(&guess);
    return guess == selected_word;
}

void WordList::to_upper_case(string* word) {
    std::transform(word->begin(), word->end(),word->begin(), ::toupper);
}

string WordList::get_selected_word() { return  selected_word; }

int WordList::get_length() {
    return words.size();
}

bool WordList::contains_word(string word) {
    for(auto &w : words) {
        if(w == word) {
            return true;
        }
    }
    return false;
}

void WordList::process_guess(int guess_num, string guess) {
    //convert entry to upper case
    to_upper_case(&guess);
    string results;
    //loop through each letter of the guess

    for(int i = 0; i < 5; i++) {
        bool remove_letter = true;
        for (char c: selected_word) {
            if (guess[i] == c) {
                remove_letter = false;
            }
        }
        if (guess[i] == selected_word[i]) {
            results.push_back(guess[i]);
            keyboard.update_letter(guess[i], LS_FoundPlaced);
        } else {
            results.push_back('*');
        }
        if (remove_letter) {
            keyboard.update_letter(guess[i], LS_Removed);
        }
    }
    guess_results[guess_num] = results;
}

void WordList::print_guess_history() {

    for(auto & guess : guess_results) {
        cout << guess.first << ".    ";
        for (auto & letter: guess.second) {
            cout << " " << letter << "  ";
        }
        cout << endl;

    }
}