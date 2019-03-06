#include "statement.h"
#include <iostream>

void Statement::prepare(Connection * con, std::string * sql) {

    reset();
    int result = sqlite3_prepare_v2(con->DB, sql->c_str(), -1, &insert_stmt, NULL);

    if (SQLITE_OK != result){
        std::cout << "ERROR IN prepare \n";
    }

  //  sqlite3_prepare_v2(db, "CREATE TABLE demo (name TEXT, age INTEGER);", -1, &stmt, NULL);
}


void Statement::bind(int const index, int const value){

     auto const result = sqlite3_bind_int(insert_stmt,
                                       index,
                                       value);

  if (SQLITE_OK != result)
  {
    std::cout << "ERROR IN BIND INT \n";    
  }
    
}

void Statement::step()
{

  int result = sqlite3_step(insert_stmt);

}

void Statement::reset()
{
    int result = sqlite3_reset(insert_stmt);

  if (SQLITE_OK != result)
  {
      std::cout << "ERROR IN RESET \n";
    }
  }
