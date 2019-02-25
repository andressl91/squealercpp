#ifndef DATABASE
#define DATABASE

#include <string>
#include <sqlite3.h>
#include <vector>
#include <map>
#include "connection.h"
#include "table.h"

using Record = std::vector<std::string>;
using Records = std::vector<Record>;
using key_val = std::pair<std::string, Table>;
using Tables = std::map<std::string, Table>;


class DataBase {
    private:
    Connection con;
    


    public:
    std::string dbPath;
    Tables tables;

    DataBase(std::string);
    void fetchTables();
    void createTable();
    //void select();
    //void insert();
    //Records select_stmt(const char* stmt);

};

#endif
