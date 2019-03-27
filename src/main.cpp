#include <iostream>
#include "pybind11.h"
#include "stl.h"

#include "database.h"
#include "sqltypes.h"
#include "table.h"


void insert1(){ 

   std::string name = "example.db";

    string_map feat;

    SqlType s_typ;
        
    feat["SEX"] = s_typ.TEXT;
    feat["PEOPLE"] = s_typ.TEXT;
    //feat["SEX"] = s_typ.INTEGER;
    //feat["PEOPLE"] = s_typ.INTEGER;
    std::string table_n = "COMPANY";

    DataBase database(name);

    database.createTable(table_n, feat);
    
    Table tbl = database.tables["COMPANY"];
    
    string_map inserts;
    //CHANGE TO INT FOR INSERT, MIGHT RESULT IN ERROR
    inserts["SEX"] = "1";
    inserts["PEOPLE"] = "2";
    tbl.Insert(inserts);
    //
    //Experimental, working, something with string vs int ?
    //tbl.InsertV2(inserts);
    
}

void insert2(){ 

   std::string name = "example.db";

    string_map feat;

    SqlType s_typ;
        
    //feat["ID"] = "REAL";
    //feat["PEOPLE"] = "REAL";
    feat["SEX"] = s_typ.TEXT;
    feat["PEOPLE"] = s_typ.TEXT;
    std::string table_n = "GROUP";

    DataBase database(name);

    database.createTable(table_n, feat);
    
    Table tbl = database.tables[table_n];
    
    //std::map<std::string, float> data;
    //data["ID"] = 1;
    //data["PEOPLE"] = 2;

    std::map<std::string, std::string> data;
    data["ID"] = "1";
    data["PEOPLE"] = "2";
    //THIS COREDUMPS WHEN RUN TWICE, WHY
    tbl.InsertV2(data);

    //tbl.InsertV3(data);
    
}
int main() {
    insert1(); 
    
    //insert2(); 



    return 0;
}
