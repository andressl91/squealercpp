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
            //std::cout << p_fields[i] << "\n"; 
            s = p_fields[i]);
            std::cout << s << "\n"; 
            //std::cout << p_col_names[i] << " " <<  p_fields[i] << "\n"; 
    }
        //std::regex word_regex("\\b[A-Z]*(?=[,\)])");
        //std::regex word_regex("\\b[A-Z]* \\b[A-Z]*(?=[,\)])");

    std::regex word_regex("\\b\\w)");

    auto words_begin =
        std::sregex_iterator(s.begin(), s.end(), word_regex);
    auto words_end = std::sregex_iterator();

    std::cout << "Found "
              << std::distance(words_begin, words_end)
              << " words\n";

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
        //if (match_str.size() > N) {
            std::cout << "  " << match_str << '\n';
        //}
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

void DataBase::buildDB() {
    char *ErrMsg = 0;
    char * sql = "PRAGMA table_info(COMPANY);";
    //char * sql = "SELECT name from PRAGMA table_info(COMPANY);";
    //char * sql = "SELECT typeof(BAG) from COMPANY;";
    //char * sql = "SELECT group_concat(name, ',') FROM pragma_table_info('COMPANY');";
    //char * sql = "SELECT sql FROM sqlite_master WHERE tbl_name = 'COMPANY' AND type = 'table'";
   
    int exit = sqlite3_open(con.db_path.c_str(), &con.DB); 
    char *errmsg;
    int rc = 0;
    //rc = sqlite3_exec(con.DB, sql, map_buildDB, &tables ,&errmsg);
    rc = sqlite3_exec(con.DB, sql, map_buildDB, NULL ,&errmsg);
    
  if (exit != SQLITE_OK) { 
    std::cerr << "Error Insert" << std::endl; 
    sqlite3_free(ErrMsg); 
    } 
    else
    {}

    sqlite3_close(con.DB); 
}


void DataBase::createTable(std::string table_name, string_map features) {

    
    std::string sql = "DROP TABLE IF EXISTS " + table_name + "; ";
    sql += "CREATE TABLE " + table_name + "(";
    
    string_map::iterator itr;
    //Only insert until second last, as last map requires special treatment
    for(itr = features.begin(); itr != --features.end(); itr++) {
        sql += itr->first + " " + itr->second + ", ";
    }
    //itr is now last element
    sql += itr->first + " " + itr->second + " ); ";

    //std::cout << sql << std::endl;
    con.query(sql);
    fetchTables();

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
