//
// Created by donald on 4/24/22.
//

#ifndef TWORD_DATABASE_H
#define TWORD_DATABASE_H

#include <string>
#include <sqlite3.h>
#include <vector>

struct Result {
    int id;
    bool won;
    int  round_num;
};

class Database {
private:
    bool debug;
    std::string db_loc;
    sqlite3 *tword_db;
    static void streaks(std::vector<Result>);

public:
    explicit Database(bool);
    std::string get_db_location() { return db_loc; };
    bool exists();
    void create();
    void insert_game(bool result, int round_num);
    void open();
    void close();
    void clear_data();
    void get_statistics();
};


#endif //TWORD_DATABASE_H
