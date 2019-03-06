#include "table.h"



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
