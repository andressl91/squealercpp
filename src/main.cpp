#include <iostream>
#include "pybind11.h"
#include "stl.h"

#include "database.h"
#include "sqltypes.h"
#include "table.h"



int main() {
   std::string name = "example.db";


    string_map feat;

    SqlType s_typ;
        
    feat["SEX"] = s_typ.INTEGER;
    feat["PEOPLE"] = s_typ.INTEGER;
    std::string table_n = "COMPANY";

    DataBase database(name);

    database.createTable(table_n, feat);
    
    Table tbl = database.tables["COMPANY"];
    //std::cout << tbl.table_name + "\n" ;
    //std::cout << tbgtl.Features()["SEX"] + "\n";
    //std::cout << tbl.con->db_path + "\n";
    
    //tbl.PreparedStatement(feat);
    
    string_map inserts;
    //CHANGE TO INT FOR INSERT, MIGHT RESULT IN ERROR
    inserts["SEX"] = "1";
    //inserts["PEOPLE"] = 2;
    //inserts["NAME"] = "HEY";
    //inserts["BAG"] = "mybag";

    tbl.Insert(inserts);
    
    return 0;
}
