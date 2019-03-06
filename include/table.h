#ifndef TABLE
#define TABLE
#include <string>
#include <map>
#include "connection.h"
#include <sqlite3.h>
#include <statement.h>



using string_map = std::map<std::string, std::string>;
class Table {
    public:
    Connection * con;
    std::string table_name;
    std::string prepared_stmt;
    string_map columns;
    Statement statement;
    
    Table();
    Table(std::string name);
    Table(std::string name, string_map column_type);
    Table(std::string name, string_map column_type, Connection *con);
    string_map Features();

    void PreparedStatement(string_map values);
    void Insert(string_map values);

};


#endif

