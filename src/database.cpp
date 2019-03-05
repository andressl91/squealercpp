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


int map_callback(void *p_data, int num_fields, char **p_fields, char **p_col_names) {

    //Tables* tbs = static_cast<Tables*>(p_data);
    for (int i = 0; i < num_fields; i++) {
            //std::cout <<  p_col_names[i] << " " <<  p_fields[i] << "\n"; 
            std::string s = std::string(p_fields[i]);
           //tbs->insert(key_val(s, Table(s))); 
    }
    return 0;
}

int map_buildDB(void *p_data, int num_fields, char **p_fields, char **p_col_names) {

    int i;
    std::string s;
    for (i = 0; i < num_fields; i++) {
            s = p_fields[i];
            std::cout << s << "\n"; 
    }

    return 0;
}

DataBase::DataBase(std::string db_path)
    : con(db_path), dbPath(db_path) {}

void DataBase::fetchTables() {
    char *ErrMsg = 0;
    char * sql = "SELECT name FROM sqlite_master where type='table'";
   
    int exit = sqlite3_open(con.db_path.c_str(), &con.DB); 
    char *errmsg;
    int rc = sqlite3_exec(con.DB, sql, map_callback, &tables ,&errmsg);
    
  if (exit != SQLITE_OK) { 
    std::cerr << "Error Insert" << std::endl; 
    sqlite3_free(ErrMsg); 
    } 
    else
    {}

    sqlite3_close(con.DB); 
}

void DataBase::fetchTableInfo() {
    con.openDB();
    int rc = 0;
    //stmt must be unique
    sqlite3_stmt *stmt2;
    sqlite3_prepare_v2(con.DB, "PRAGMA table_info(COMPANY);", -1, &stmt2, NULL);
    //TODO: Implement map for column_name and column_type. Used for table
    //constructor
    while( (rc = sqlite3_step(stmt2)) == SQLITE_ROW){
        std::cout << sqlite3_column_text(stmt2, 1) << " " <<sqlite3_column_text(stmt2, 2) << "\n";
    }

    if (rc != SQLITE_DONE){
        std::cout << "FAILED PRAGMA \n";
    }
    else {
        std::cout << "SOME PRAGMA WORKED \n";
    }
    sqlite3_finalize(stmt2);
    con.closeDB();

}


void DataBase::createTable(std::string table_name, string_map features) {

    // TODO: THIS WILL PURGE EXISTING TABLE, DO CHECKS ETC 
    //std::string sql = "DROP TABLE IF EXISTS " + table_name + "; ";
    std::string sql;
    sql += "CREATE TABLE " + table_name + "(";
    
    string_map::iterator itr;
    //Only insert until second last, as last map requires special treatment
    for(itr = features.begin(); itr != --features.end(); itr++) {
        sql += itr->first + " " + itr->second + ", ";
    }
    //itr is now last element
    sql += itr->first + " " + itr->second + "); ";
    std::cout << sql << std::endl;
    
    con.openDB();
    int rc;
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(con.DB, sql.c_str(), -1, &stmt, NULL);
     rc = sqlite3_step(stmt);
 
    if (rc != SQLITE_DONE){
        std::cout << "FAILED CREATING TABLE \n";
    }
    else {
        std::cout << "CREATED TABLE \n";
    }

   sqlite3_finalize(stmt); 
   con.closeDB();
   //fetchTables();
}

void DataBase::deleteME() {
int exit = sqlite3_open(con.db_path.c_str(), &con.DB); 


    char *ErrMsg = 0;
    const char * table = "COMPANY";
    const char * colname = "NAME";


    const char ** ret1;
    const char ** ret2;

    int * ret3;
    int * ret4;
    int * ret5;

    int rc = sqlite3_table_column_metadata(con.DB,
            con.db_path.c_str(), table, colname,
            ret1, ret2, ret3, ret4, ret5
            );

  if (exit != SQLITE_OK) { 
    std::cerr << "Error Insert" << std::endl; 
    sqlite3_free(ErrMsg); 
    } 
    else
    {}

    sqlite3_close(con.DB); 

}


//int sqlite3_table_column_metadata(
//  sqlite3 *db,                /* Connection handle */
//  const char *zDbName,        /* Database name or NULL */
//  const char *zTableName,     /* Table name */
//  const char *zColumnName,    /* Column name */
//  char const **pzDataType,    /* OUTPUT: Declared data type */
//  char const **pzCollSeq,     /* OUTPUT: Collation sequence name */
//  int *pNotNull,              /* OUTPUT: True if NOT NULL constraint exists */
//  int *pPrimaryKey,           /* OUTPUT: True if column part of PK */
//  int *pAutoinc               /* OUTPUT: True if column is auto-increment */
//    ); */
