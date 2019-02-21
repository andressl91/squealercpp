#ifndef DATABASE
#define DATABASE

#include <string>
#include <sqlite3.h>
#include <vector>
#include "connection.h"

using Record = std::vector<std::string>;
using Records = std::vector<Record>;

class DataBase {
    private:
    Connection con;


    public:
    DataBase(std::string);
    void fetchTables();
    void createTable();
    void select();
    void insert();
    Records select_stmt(const char* stmt);

};

#endif
