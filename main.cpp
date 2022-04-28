#include <iostream>
#include "main.h"
#include "WordList.h"
#include "database.h"

using namespace std;

bool debug = false;
bool reset = false;
string version;

int main(int argc, char *argv[]) {
    version = "v0.1.2-beta";
    parse_arguments(argc, argv);

    Database db(debug);
    if (!db.exists()) {
        if(debug) {
            cout << db.get_db_location() << " does not exist" << endl;
        }
        db.create();
    }

    //open the database for the game
    db.open();

    //delete all results if -r flag is set
    if(reset) {
        db.clear_data();
    }

    bool quit = false;
    while (!quit) {
        int result = game();
        if(debug) {
            cout << "[DEBUG] INSERTING " << result << " To Database." << endl;
        }
        if (result > 0) {
            db.insert_game(true, result);
        } else {
            db.insert_game(false, 0);
        }
        db.get_statistics();
        string response;
        cout << "Play Again Y/N: ";
        cin >> response;
        if (response != "Y") {
            quit = true;
        }
    }

    //close the database connection
    db.close();

}

int game() {
    WordList word_list;
    for (int i = 1; i <= 6; i++) {
        system("clear");
        if (debug) {
            cout << "[DEBUG] selected word:" << word_list.get_selected_word() << endl;
        }
        cout << "TWORD, " << version << endl;

        string guess;
        bool valid_guess = false;
        if (i > 1) {
            word_list.print_guess_history();
            cout << "\n------------------------------" << endl;
            word_list.print_keyboard();
        }

        while (!valid_guess) {
            cout << "\nGuess the word (" << i << "/6) : ";
            cin >> guess;
            valid_guess = validate_guess(guess);
        }

        word_list.process_guess(i, guess);

        if (word_list.guess_selected_word(guess)) {
            cout << "\nYou won, the secret word was: " << word_list.get_selected_word() << endl;
            return i;
        }
    }

    system("clear");
    cout << "TWORD, " << version << endl << endl;
    word_list.print_guess_history();
    cout << "\nSorry, The secret word was: " << word_list.get_selected_word() << endl;
    return 0;
}

bool validate_guess(const string &guess) {
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

void parse_arguments(int &argc, char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        //print the usage message
        if ((arg == "-h") || (arg == "--help")) {
            usage(argv[0]);
        }

        //set the reset data flag
        if ((arg == "-r") || arg == "--reset") {
            reset = true;
        }

        //set the debug messages flag
        if ((arg == "-d") || (arg == "--debug")) {
            debug = true;
        }
    }
}

static void usage(const string &name) {
    cerr << "Usage: " << name << " <option(s)>\n"
         << "Options:\n"
         << "\t-h,--help\t\tShow this help message\n"
         << "\t-d,--debug\tDisplay debug messages\n"
         << "\t-r, --reset\tClear statistical data\n"
         << endl;
    exit(0);
}
