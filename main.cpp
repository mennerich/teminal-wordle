#include <iostream>
#include "WordList.h"

using namespace std;

const string version = "v0.1.0-alpha";

int main() {
    WordList word_list;
    cout << "Terminal Wordle, version" <<  version << endl;
    cout << "Loading dictionary file" << endl;
    cout << "  * loaded " << word_list.get_length() << " records" << endl;

    string guess;

    for(int i = 1; i <=5; i++) {
        cout << "\nGuess the word: ";
        cin >> guess;

        word_list.process_guess(i, guess);

        if(word_list.guess_selected_word(guess)) {
            cout << "You won" << endl;
            return 0;
        }

        word_list.print_guess_history();
    }

    cout << "\nSorry, The secret word was " << word_list.get_selected_word() << endl;
    return 0;
}
