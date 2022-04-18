#include <iostream>
#include "WordList.h"
#include "Keyboard.h"

using namespace std;

const string version = "v0.1.0-alpha";

int main() {
    WordList word_list;
    string guess;
    system("clear");
    cout << "Terminal Wordle, " <<  version << endl;
    //cout << word_list.get_selected_word() << endl;

    for(int i = 1; i <=5; i++) {

        cout << "\nGuess the word: ";
        cin >> guess;
        system("clear");
        word_list.process_guess(i, guess);

        cout << "Terminal Wordle, " <<  version << endl << endl;
        word_list.print_guess_history();
        if(word_list.guess_selected_word(guess)) {
            cout << "\nYou won!" << endl;
            return 0;
        }


        cout << "\n------------------------------" << endl;
        word_list.print_keyboard();
    }

    cout << "\nSorry, The secret word was " << word_list.get_selected_word() << endl;
    return 0;
}
