#include "table.h"
#include <iostream>


using string_map = std::map<std::string, std::string>;

Table::Table() 
{}

Table::Table(std::string name) 
    : table_name(name)
{
    
}
Table::Table(std::string name, string_map column_type) 
    : table_name(name), columns(column_type)
{}

Table::Table(std::string name, string_map column_type, Connection *connection) 
    : table_name(name), columns(column_type), con(connection)
{
}

string_map Table::Features(){
    return columns;
}

void Table::Insert(string_map values) {
    //Define sql statement AND sqlite3_pepare_v2 ONCE
    //sqlite3_stmt *insert;
    
    //string_map::iterator itr;
    //for (itr = values.begin(); itr != values.end(); itr++){
    //    std::cout << itr->first << " " << itr->second << "\n";
    //}

    string_map::iterator itr;
    std::string sql = "INSERT INTO " + table_name + "(";
    for (itr = values.begin(); itr != --values.end(); itr++){
        sql += itr->first + ",";
    }
    sql += itr->first + ")";

    std::cout << sql << std::endl;

    sql += "(col1 col2)";
    sql += "VALUES";
    sql += "(?1 ?2)"; //make using length of talbe columns map
    //sqlite3_prepare_v2(*con.DB, )
 
    /**
    text = f"INSERT INTO {self._table_name}"
   features = "(" + ",".join(cat for cat in sql_data) + ")"
    nr_values = "VALUES(" + ",".join("?" * len(sql_data)) + ")"
    */

}
