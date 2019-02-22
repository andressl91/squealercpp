#include <string>
#include <iostream>
#include "database.h"
#include "connection.h"

template <typename T>
void printRecords(std::vector<T> v) {
    for(int i=0; i != v.size() ; i++) {
        std::cout << v.at(i) << " ";
            }
    std::cout << std::endl;
}

static int callback(void *data, int argc, char **argv, char **ColName) {
    int i;
    std::cout << "We are in the callback: \n";
    
    //std::cout << *data << std::endl;
    for (i=0; i < argc; i++) {
        std::cout << ColName[i] << " " <<argv[i] << std::endl;
    }
    std::cout << "END OF CALLBACK \n";
    return 0;

}

int select_callback(void *p_data, int num_fields, char **p_fields, char **p_col_names) {
    Records* records = static_cast<Records*>(p_data);
    try {
        records->emplace_back(p_fields, p_fields + num_fields);
    }

    catch (...){
        return 1;
    }

    for (int i = 0; i < num_fields; i++) {
        std::cout <<  p_col_names[i] << " " <<  p_fields[i] << "\n"; 
    }
    return 0;
}



DataBase::DataBase(std::string db_path): con(db_path)
{
    
}

void DataBase::fetchTables() {

    char *ErrMsg = 0;
    char * sql = "SELECT name FROM sqlite_master where type='table'";
    
    int exit = sqlite3_open("example.db", &con.DB); 
    //ORIGINAL WORKS
    //TODO make callback with map
    int rc = sqlite3_exec(con.DB, sql, callback, NULL, &ErrMsg);
    // TEST
    //Records records;
    //char *errmsg;
    // sql is stmt
   // exit = sqlite3_open("example.db", &con.DB); 
 //   int ret = sqlite3_exec(con.DB, sql, select_callback, &records, &errmsg);

    //
  if (exit != SQLITE_OK) { 
    std::cerr << "Error Insert" << std::endl; 
    sqlite3_free(ErrMsg); 
    } 
    else
        std::cout << "Fetch tablese successfully!" << std::endl; 

    sqlite3_close(con.DB); 

    //std::cout << records.at(0) << std::endl;

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

Records DataBase::select_stmt(const char* stmt) {
    Records records;
    int exit;
    char *errmsg;
    // sql is stmt
    exit = sqlite3_open("example.db", &con.DB); 
    int ret = sqlite3_exec(con.DB, stmt, select_callback, &records, &errmsg);
    if (ret != SQLITE_OK) {
        std::cerr << "Error in select statement " << stmt << "[" << errmsg << "]\n";
    }
    else {
        std::cerr << records.size() << " records returned. \n";
    }
    sqlite3_close(con.DB); 
    return records;
}

void DataBase::deleteme() {
    std::map<std::string, Table> test_map; 
    Table test_table;
    test_table.name = "HOla";
    
    test_map.insert(key_val("test", test_table));

    Table key = test_map.find("test")->second;

    std::cout << key.name << std::endl;


}


