#include <iostream>
#include "database.h"



int main() {
   std::string name = "student.db";

    DataBase database(name);
    //database.createTable();
    database.fetchTables();
    std::cout << "HERE";
    return 0;
}
