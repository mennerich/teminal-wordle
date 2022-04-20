#include <iostream>
#include "WordList.h"
#include "Keyboard.h"

using namespace std;

const string version = "v0.1.0-alpha";
bool validate_guess(string);
WordList *word_list;

int main() {
    word_list = new WordList();
    system("clear");

    cout << "Terminal Wordle, " <<  version << endl;
    //cout << word_list.get_selected_word() << endl;

    for(int i = 1; i <=5; i++) {
        cout << endl;
        string guess;
        bool valid_guess = false;
        while(!valid_guess) {
            cout << "Guess the word: ";
            cin >> guess;
            valid_guess = validate_guess(guess);
        }
        system("clear");
        word_list->process_guess(i, guess);

        cout << "Terminal Wordle, " <<  version << endl << endl;
        word_list->print_guess_history();
        if(word_list->guess_selected_word(guess)) {
            cout << "\nYou won!" << endl;
            return 0;
        }


        cout << "\n------------------------------" << endl;
        word_list->print_keyboard();
    }

    cout << "\nSorry, The secret word was: " << word_list->get_selected_word() << endl;
    return 0;
}

bool validate_guess(string guess) {
    if(guess.size() != 5) {
        cout << "!! " << guess << " is not a 5-letter word" << endl;
        return false;
    }

    if(!word_list->contains_word(guess)) {
        cout << "!! " << guess << " is not in word list" << endl;
        return false;
    }

    return true;
}