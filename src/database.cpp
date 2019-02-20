#include <string>
#include <iostream>
#include "database.h"
#include "connection.h"

static int callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    std::cout << "We are in the callback";
    for (i=0; i < argc; i++) {
        std::cout << azColName[i] << " " <<argv[i] << std::endl;
    }
    return 0;

}


DataBase::DataBase(std::string db_path): con(db_path)
{
    
}

void DataBase::fetchTables() {

   ("SELECT name FROM sqlite_master where type='table'");
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


void DataBase::select() {

    char *zErrMsg = 0;
    int rc;
    const char* data = "Callback function called";
    //std::string sql = "SELECT * from COMPANY";
    char * sql = "SELECT * from COMPANY";
    
    int exit = 0; 
    exit = sqlite3_open("example.db", &con.DB); 
    rc = sqlite3_exec(con.DB, sql, callback, (void*)data, &zErrMsg);
    sqlite3_close(con.DB); 
}

/*    
    std::string sql = "DROP TABLE IF EXISTS PERSON;"
                      "CREATE TABLE PERSON("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "NAME           TEXT    NOT NULL, "
                      "SURNAME          TEXT     NOT NULL, "
                      "AGE            INT     NOT NULL, "
                      "ADDRESS        CHAR(50), "
                      "SALARY         REAL );"; 
    con.query(sql);*/
