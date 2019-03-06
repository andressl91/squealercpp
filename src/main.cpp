#include <iostream>
#include "database.h"
#include "sqltypes.h"



int main() {
   std::string name = "example.db";


    string_map feat;

    SqlType s_typ;
        
    feat["SEX"] = s_typ.INTEGER;
    feat["NAME"] = s_typ.TEXT;
    feat["BAG"] = s_typ.TEXT;
    std::string table_n = "COMPANY";

    DataBase database(name);

    database.createTable(table_n, feat);
    //database.fetchTableInfo(table_n);
    //database.deleteME();
    
    Table tbl = database.tables["COMPANY"];
    std::cout << tbl.table_name + "\n" ;
    std::cout << tbl.Features()["NAME"] + "\n";
    std::cout << tbl.con->db_path + "\n";
    
    
    string_map inserts;
    //CHANGE TO INT FOR INSERT, MIGHT RESULT IN ERROR
    inserts["SEX"] = "1";
    inserts["NAME"] = "HEY";
    inserts["BAG"] = "mybag";

    tbl.Insert(inserts);
    
    return 0;
}
