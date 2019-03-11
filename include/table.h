#ifndef TABLE
#define TABLE
#include "pybind11.h"
#include "stl.h"
#include <string>
#include <map>
#include "connection.h"
#include <sqlite3.h>
#include "statement.h"


namespace py = pybind11;
using py_map = std::map<std::string, py::object>;

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

    template <typename T>
    void PreparedStatement(T values);
    //void PreparedStatement(string_map values);
    void Insert(py_map values);
    void Insert(string_map values);

};


#endif

