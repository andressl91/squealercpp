#include <iostream>
#include "database.h"



int main() {
   std::string name = "student.db";


    string_map feat;

    feat["ID"] = "INT";
    feat["NAME"] = "TEXT";
    std::string table_n = "COMPANY";

    DataBase database(name);
    database.createTable(table_n, feat);
    //database.fetchTables();
    return 0;
}
