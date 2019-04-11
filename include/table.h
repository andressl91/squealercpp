#ifndef TABLE
#define TABLE
#include <string>
#include <map>
#include "connection.h"
#include <sqlite3.h>
#include "statement.h"
#include <vector>

/*
#include "pybind11.h"
#include "stl.h"
namespace py = pybind11;
using py_map = std::map<std::string, py::object>;
using py_map_vector = std::vector<py_map>;
*/
using string_map = std::map<std::string, std::string>;
class Table {
    public:
    Connection * con;
    std::string table_name;
    std::string prepared_stmt;
    string_map columns;
    Statement statement;
    Statement multi_statement;
    
    Table();
    Table(std::string name, string_map column_type, Connection *con);
    string_map Features();

    template <typename T>
    void PreparedStatement(T values);
    void MultiPreparedStatement(const int);
    //void PreparedStatement(string_map values);
    void Insert(string_map  values);

    //void InsertTemplate(std::map<std::string, T>  values);
    template <typename U>
    void InsertTemplate(U values);




};


#endif

