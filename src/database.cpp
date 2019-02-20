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

    char *zErrMsg = 0;
    int rc;
    const char* data = "Callback function called for fetchTables";
    char * sql = "SELECT name FROM sqlite_master where type='table'";
    
    int exit = 0; 
    exit = sqlite3_open("example.db", &con.DB); 
    rc = sqlite3_exec(con.DB, sql, callback, (void*)data, &zErrMsg);
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

void DataBase::insert() {
    char* messaggeError;
    int exit = sqlite3_open("example.db", &con.DB);
    std::string sql("INSERT INTO COMPANY VALUES(1, 'STEVE', 'GATES', 30, 'PALO ALTO', 1000.0);"
               "INSERT INTO COMPANY VALUES(2, 'BILL', 'ALLEN', 20, 'SEATTLE', 300.22);"
               "INSERT INTO COMPANY VALUES(3, 'PAUL', 'JOBS', 24, 'SEATTLE', 9900.0);");

    exit = sqlite3_exec(con.DB, sql.c_str(), NULL, 0, &messaggeError);
    sqlite3_close(con.DB);
}


void DataBase::select() {


    std::cout << "HERE \n";
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
