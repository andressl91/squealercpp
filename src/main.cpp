#include <iostream>
#include "database.h"



int main() {
   std::string name = "student.db";

    DataBase database(name);
    //database.createTable();
    //database.insert();
    //database.select();
    database.fetchTables();
    //char * sql = "SELECT * from COMPANY";
    //Records records;
    //records = database.select_stmt(sql);
    //std::cerr << records.size() << " records returned. \n";

   /*
   Connection con(name);

    std::string sql = "DROP TABLE IF EXISTS PERSON;"
                      "CREATE TABLE PERSON("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "NAME           TEXT    NOT NULL, "
                      "SURNAME          TEXT     NOT NULL, "
                      "AGE            INT     NOT NULL, "
                      "ADDRESS        CHAR(50), "
                      "SALARY         REAL );"; 
   con.query(sql);
*/
    return 0;
}
