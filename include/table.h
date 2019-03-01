#ifndef TABLE
#define TABLE
#include <string>
#include <map>



class Table {
    public:
    std::string table_name;
    std::map<std::string, std::string> columns;

    Table(std::string name);
    Table(std::string name, std::map<std::string, std::string>);
    Table();

};


#endif

