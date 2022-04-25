//
// Created by donald on 4/24/22.
//

#include <iostream>
#include <string>
#include <sys/stat.h>
#include <filesystem>
#include "database.h"
#include "sqlite3.h"

using namespace std;

Database::Database(bool debug_i) {
    debug = debug_i;
    filesystem::path home = getenv("HOME");
    filesystem::path local = ".local";
    filesystem::path db = "tword.db";
    filesystem::path db_path = home / local / db;
    db_loc = db_path.generic_string();
}

int callback(void *NotUsed, int argc, char **argv, char **azColName){
    cout << "HI";
    return 0;
}

bool Database::exists() {
    struct stat buffer{};
    return (stat (db_loc.c_str(), &buffer) == 0);
}

void Database::open() {
    int db_open = sqlite3_open(db_loc.c_str(), &tword_db);
    if(!db_open) {
        if(debug) {
            cout << "DB Opened" << endl;
        }
    } else {
        cerr << "DB Error: " << sqlite3_errmsg(tword_db) << endl;
    }
}

void Database::close() {
    int db_close = sqlite3_close(tword_db);
    if(!db_close) {
        if(debug) {
            cout << "DB Closed" << endl;
        }
    } else {
        cerr << "DB ERROR: " <<sqlite3_errmsg(tword_db) << endl;
    }
}

void Database::create() {
    if(debug) {
        cout << "Creating Database" << endl;
    }
    open();
    string stmt = "CREATE TABLE RESULTS ("  \
      "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
      "RESULT BOOL NOT NULL," \
      "ROUND_NUM INT);";

    char *zErrMsg = nullptr;
    int create_table = sqlite3_exec(tword_db, stmt.c_str(), callback, nullptr, &zErrMsg);
    if (create_table) {
        if(debug) {
            cerr << "DB Table Create Error: " << sqlite3_errmsg(tword_db) << endl;
        }
    } else {
        cout << "Table Created Successfully!" << endl;
    }
    close();
}

void Database::insert_game(bool result, int round_num) {
    open();
    char buffer [100];
    auto stmt = sprintf(buffer, "INSERT INTO RESULTS(RESULT, ROUND_NUM) VALUES(%d,%d)", result, round_num);
    char *zErrMsg = nullptr;
    int insert = sqlite3_exec(tword_db, buffer, callback, nullptr, &zErrMsg);
    if(insert) {
        cerr << "DB Data Insert Error: " << sqlite3_errmsg(tword_db) << endl;
    } else {
        if(debug) {
            cout << "DB Data Inserted Successfully!" << endl;
        }
    }
    close();
}

