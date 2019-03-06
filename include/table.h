#ifndef TABLE
#define TABLE
#include <string>
#include <map>
#include "connection.h"
#include <sqlite3.h>



using string_map = std::map<std::string, std::string>;
class Table {
    public:
    Connection * con;
    std::string table_name;
    string_map columns;
    
    Table();
    Table(std::string name);
    Table(std::string name, string_map column_type);
    Table(std::string name, string_map column_type, Connection *con);
    string_map Features();

    void Insert(string_map values);

};


#endif

