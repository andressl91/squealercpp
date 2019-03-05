#ifndef TABLE
#define TABLE
#include <string>
#include <map>


using string_map = std::map<std::string, std::string>;

class Table {
    public:
    std::string table_name;
    string_map columns;

    Table(std::string name);
    Table(std::string name, string_map column_type);
    Table();

};


#endif

