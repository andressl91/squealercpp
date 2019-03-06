#include <string>
#include <iostream>
#include "database.h"
#include "connection.h"
#include <map>
#include <sqlite3.h>

//DEVELOP
#include <regex>


template <typename T>
void printRecords(std::vector<T> v) {
    for(int i=0; i != v.size() ; i++) {
        std::cout << v.at(i) << " ";
            }
    std::cout << std::endl;
}



DataBase::DataBase(std::string db_path)
    : con(db_path), dbPath(db_path) {}

void DataBase::buildDB(){
    tables.clear();
    fetchTables();
}

void DataBase::fetchTables() {
    con.openDB();
    int rc = 0;
    //stmt must be unique
    sqlite3_stmt *stmt3;
    char * sql = "SELECT name FROM sqlite_master where type='table'";
    sqlite3_prepare_v2(con.DB, sql, -1, &stmt3, NULL);

    char * st;
    while( (rc = sqlite3_step(stmt3)) == SQLITE_ROW){
        std::string table_name(reinterpret_cast<const char*>(sqlite3_column_text(stmt3, 0)));
        string_map table_info = fetchTableInfo(table_name);
        tables[table_name] = Table(table_name, table_info, &con);
    }

    if (rc != SQLITE_DONE){
        std::cout << " FAILED TO FETCH TABLES \n";
    }
    else {
    }
    sqlite3_finalize(stmt3);
    con.closeDB();
}

string_map DataBase::fetchTableInfo(std::string table_name) {
    con.openDB();
    int rc = 0;
    std::string pragma_sql = "PRAGMA table_info(" + table_name + ");";
    sqlite3_stmt *stmt2;
    sqlite3_prepare_v2(con.DB, pragma_sql.c_str(), -1, &stmt2, NULL);
    string_map column_map;
    
    while( (rc = sqlite3_step(stmt2)) == SQLITE_ROW){
        std::string column_name(reinterpret_cast<const char*>(sqlite3_column_text(stmt2, 1)));
        std::string data_type(reinterpret_cast<const char*>(sqlite3_column_text(stmt2, 2)));
        column_map[column_name] = data_type;
    }


    if (rc != SQLITE_DONE){
        std::cout << "FAILED PRAGMA \n";
    }
    else {
    }
    sqlite3_finalize(stmt2);
    con.closeDB();

    return column_map;

}


void DataBase::createTable(std::string table_name, string_map features, bool overwrite) {

    if(overwrite) {
        dropTable(table_name);
    }
    std::string sql;
    sql += "CREATE TABLE " + table_name + "(";
    
    string_map::iterator itr;
    //Only insert until second last, as last map requires special treatment
    for(itr = features.begin(); itr != --features.end(); itr++) {
        sql += itr->first + " " + itr->second + ", ";
    }
    //itr is now last element
    sql += itr->first + " " + itr->second + "); ";
    //std::cout << sql << std::endl;
    
    con.openDB();
    int rc;
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(con.DB, sql.c_str(), -1, &stmt, NULL);
     rc = sqlite3_step(stmt);
 
    if (rc != SQLITE_DONE){
        std::cout << "FAILED CREATING TABLE \n";
    }
    else {
    }

   sqlite3_finalize(stmt); 
   con.closeDB();
   buildDB();
}


void DataBase::dropTable(std::string table_name) {
    std::string sql;
    sql += "DROP TABLE " + table_name + ";";
    
    
    con.openDB();
    int rc;
    sqlite3_stmt *rm_stmt;
    sqlite3_prepare_v2(con.DB, sql.c_str(), -1, &rm_stmt, NULL);
     rc = sqlite3_step(rm_stmt);
 
    if (rc != SQLITE_DONE){
        std::cout << "FAILED CREATING TABLE \n";
    }
    else {
    }

   sqlite3_finalize(rm_stmt); 
   con.closeDB();
   buildDB();
}


