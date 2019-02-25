#include <string>
#include <iostream>
#include "database.h"
#include "connection.h"
#include <map>
#include <sqlite3.h>

template <typename T>
void printRecords(std::vector<T> v) {
    for(int i=0; i != v.size() ; i++) {
        std::cout << v.at(i) << " ";
            }
    std::cout << std::endl;
}


int map_callback(void *p_data, int num_fields, char **p_fields, char **p_col_names) {

    Tables* tbs = static_cast<Tables*>(p_data);
    for (int i = 0; i < num_fields; i++) {
            //std::cout <<  p_col_names[i] << " " <<  p_fields[i] << "\n"; 
            std::string s = std::string(p_fields[i]);
           tbs->insert(key_val(s, Table(s))); 
    }
    return 0;
}



DataBase::DataBase(std::string db_path)
    : con(db_path), dbPath(db_path) {}

void DataBase::fetchTables() {

    char *ErrMsg = 0;
    char * sql = "SELECT name FROM sqlite_master where type='table'";
    
    int exit = sqlite3_open("example.db", &con.DB); 
    char *errmsg;
    int rc = sqlite3_exec(con.DB, sql, map_callback, &tables ,&errmsg);
    

  if (exit != SQLITE_OK) { 
    std::cerr << "Error Insert" << std::endl; 
    sqlite3_free(ErrMsg); 
    } 
    else
        std::cout << "Fetch tablese successfully!" << std::endl; 

    sqlite3_close(con.DB); 
}

void DataBase::createTable() {
    
    std::string sql = "DROP TABLE IF EXISTS COMPANY;"
                      "CREATE TABLE COMPANY("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "NAME           TEXT    NOT NULL, "
                      "SURNAME          TEXT     NOT NULL, "
                      "AGE            INT     NOT NULL, "
                      "ADDRESS        CHAR(50), "
                      "SALARY         REAL );"; 
    con.query(sql);

}






