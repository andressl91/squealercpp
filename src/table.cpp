#include "table.h"


Table::Table() {

}

Table::Table(std::string name) 
    : table_name(name)
{
    
}

Table::Table(std::string name, string_map column_type) 
    : table_name(name), columns(column_type)
{}

