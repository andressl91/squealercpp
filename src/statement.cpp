#include "statement.h"
#include <iostream>


Statement::Statement() {}

void Statement::prepare(Connection * con, std::string sql) {

    //reset();
    //con->openDB(); 
    this->connection = con;

    connection->openDB();
    int result = sqlite3_prepare_v2(con->DB, sql.c_str(), sql.length(), &insert_stmt, NULL);
    if (SQLITE_OK != result){
        std::cout << "ERROR IN prepare \n";
    }

    connection->closeDB();
}

void Statement::bind2(int* index, int * value){
     auto const result = sqlite3_bind_int(insert_stmt,
                                        *index,
                                        *value);
  if (SQLITE_OK != result)
  {
    std::cout << "ERROR IN BIND INT \n";    
  }
    
}

void Statement::bind(const int index, const int value){
     auto const result = sqlite3_bind_int(insert_stmt,
                                        index,
                                        value);
  if (SQLITE_OK != result)
  {
    std::cout << "ERROR IN BIND INT \n";    
  }
    
}

void Statement::bind(const int index, const float value){
     auto const result = sqlite3_bind_double(insert_stmt,
                                        index,
                                        value);
  if (SQLITE_OK != result)
  {
    std::cout << "ERROR IN BIND FLOAT \n";    
  }
}

void Statement::bind2(int *index, float *value){
     auto const result = sqlite3_bind_double(insert_stmt,
                                        *index,
                                        *value);
  if (SQLITE_OK != result)
  {
    std::cout << "ERROR IN BIND FLOAT \n";    
  }
}

void Statement::bind(const int index, const std::string   value){
    auto const result = sqlite3_bind_text(insert_stmt,
                                         index,
                                        value.c_str(),
                                        value.length(),
                                        SQLITE_STATIC);
  if (SQLITE_OK != result)
  {
    std::cout << "ERROR IN BIND TEXT \n";    
  }
}

void Statement::bind2(int *index, std::string* value){
    auto const result = sqlite3_bind_text(insert_stmt,
                                        * index,
                                        value->c_str(),
                                        value->length(),
                                        SQLITE_STATIC);
  if (SQLITE_OK != result)
  {
    std::cout << "ERROR IN BIND TEXT \n";    
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
