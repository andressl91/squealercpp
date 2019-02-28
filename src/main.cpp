#include <iostream>
#include "database.h"
#include "sqltypes.h"



int main() {
   std::string name = "student.db";


    string_map feat;

    SqlType s_typ;
        
    feat["ID"] = s_typ.INTEGER;
    feat["NAME"] = s_typ.TEXT;
    std::string table_n = "COMPANY";

    DataBase database(name);
    database.createTable(table_n, feat);
    //database.fetchTables();
    return 0;
}
