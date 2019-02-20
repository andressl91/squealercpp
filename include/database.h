#ifndef DATABASE
#define DATABASE

#include <string>
#include <sqlite3.h>
#include "connection.h"


class DataBase {
    private:
    Connection con;


    public:
    DataBase(std::string);
    void fetchTables();
    void createTable();
    void select();

};

#endif
