#ifndef TABLE
#define TABLE
#include <string>
#include <map>



using string_map = std::map<std::string, std::string>;
class Table {
    public:
    std::string table_name;
    string_map columns;
    
    Table();
    Table(std::string name);
    Table(std::string name, string_map column_type);
    string_map Features();

};


#endif

