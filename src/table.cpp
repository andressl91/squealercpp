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

void Table::PreparedStatement(string_map values) {
    string_map::iterator itr;
    std::string sql = "INSERT INTO " + table_name + " (";
    for (itr = values.begin(); itr != --values.end(); itr++){
        sql += itr->first + ",";
    }
    sql += itr->first + ") ";
    
    sql += "VALUES (";

    for (itr = values.begin(); itr != --values.end(); itr++){
        sql += "?, ";
    }
    sql += "?);";

    prepared_stmt = sql;
    std::cout << prepared_stmt << std::endl;

    statement.prepare(con, prepared_stmt);

}

void Table::Insert(string_map values) {
/**
    for (auto item: values) {
  auto key = item.first;
  if (pybind11::str(key).check()) {
    // do something on str.
      std::cout << "HEllo STRING \n";
  } else if (pybind11::int_(key).check()) {
      std::cout << "HELLO INT \n";
  }
  ...
}
*/
    //Define sql statement AND sqlite3_pepare_v2 ONCE
    PreparedStatement(values);
    string_map::iterator itr;
    int i = 1;
    for (itr = values.begin(); itr != values.end(); itr++){
        std::cout << itr->first << " " << itr->second << "\n";
        statement.bind(i, itr->second);
        i++;
    }

    statement.step();


}
