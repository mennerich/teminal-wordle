#include <iostream>
#include "WordList.h"
#include "Keyboard.h"

using namespace std;

bool validate_guess(const string&);
static void usage(const string &);
static WordList *word_list;
void parse_arguments(int&, char**);
bool debug = false;

int main(int argc, char* argv[]) {
    const string version = "v0.1.1-beta";
    parse_arguments(argc, argv);
    word_list = new WordList();

    for (int i = 1; i <= 6; i++) {
        system("clear");
        if(debug) {
            cout << "[DEBUG] selected word:" << word_list->get_selected_word() << endl;
        }
        cout << "TWORD, " << version << endl;

        string guess;
        bool valid_guess = false;
        if (i > 1) {
            word_list->print_guess_history();
            cout << "\n------------------------------" << endl;
            word_list->print_keyboard();
        }

        while (!valid_guess) {
            cout << "\nGuess the word (" << i << "/6) : ";
            cin >> guess;
            valid_guess = validate_guess(guess);
        }

        word_list->process_guess(i, guess);

        if (word_list->guess_selected_word(guess)) {
            cout << "\nYou won, the secret word was: " << word_list->get_selected_word() << endl;
            return 0;
        }
    }

    system("clear");
    cout << "TWORD, " << version << endl << endl;
    word_list->print_guess_history();
    cout << "\nSorry, The secret word was: " << word_list->get_selected_word() << endl;
    return 0;
}

bool validate_guess(const string& guess) {
    if (guess.size() != 5) {
        cout << "!! " << guess << " is not a 5-letter word" << endl;
        return false;
    }

    if (!WordList::contains_word(guess)) {
        cout << "!! " << guess << " is not in word list" << endl;
        return false;
    }

    return true;
}

void parse_arguments(int & argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if ((arg == "-h") || (arg == "--help")) {
            usage(argv[0]);
        }

        if ((arg == "-d") || (arg == "--debug")) {
            debug = true;
        }
    }
}

static void usage(const string& name)
{
    cerr << "Usage: " << name << " <option(s)>\n"
              << "Options:\n"
              << "\t-h,--help\t\tShow this help message\n"
              << "\t-d,--debug\tDisplay debug messages"
              << endl << endl;
    exit(0);
}