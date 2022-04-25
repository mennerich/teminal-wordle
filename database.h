//
// Created by donald on 4/24/22.
//

#ifndef TWORD_DATABASE_H
#define TWORD_DATABASE_H

#include <string>
#include <sqlite3.h>

class Database {
private:
    bool debug;
    std::string db_loc;
    sqlite3 *tword_db;

public:
    explicit Database(bool);
    bool exists();
    void create();
    void insert_game(bool result, int round_num);
    void open();
    void close();
};


#endif //TWORD_DATABASE_H
