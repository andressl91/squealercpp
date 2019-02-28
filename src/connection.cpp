#include "connection.h"
#include <iostream>

Connection::Connection(std::string sql_db_path) 
 : db_path(sql_db_path){}

void Connection::openDB() {
    
  //sqlite3 *DB;
 
  char *err_message = 0;

  int rc = sqlite3_open("student.db", &DB);

  if (rc != SQLITE_OK) {

    sqlite3_close(DB);
    //return 1;

  } else {
      std::cout <<  "Connected successfully \n";
  }
}


void Connection::closeDB() {
    sqlite3_close(DB);
}


void Connection::query(std::string sql) {

    int exit = 0; 
    exit = sqlite3_open(db_path.c_str(), &DB); 
    char* messaggeError; 
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError); 
  
    if (exit != SQLITE_OK) { 
        std::cerr << "Error excecuting query" << sql <<std::endl; 
        sqlite3_free(messaggeError); 
    } 
    else
        std::cout << "Query Successfull" << std::endl; 
    sqlite3_close(DB); 

}
