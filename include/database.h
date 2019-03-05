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
using string_map = std::map<std::string, std::string>;


class DataBase {
    private:
    Connection con;
    


    public:
    std::string dbPath;
    Tables tables;

    DataBase(std::string);
    void createTable(std::string table_name, string_map featues, bool overwrite=false) ;
    string_map fetchTableInfo(std::string table_name);
    void fetchTables();
    void dropTable(std::string table_name);
    void buildDB();
    void deleteME();
    //void select();
    //void insert();
    //Records select_stmt(const char* stmt);

};

#endif
