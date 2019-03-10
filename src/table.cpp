#include "table.h"
#include "pybind11.h"
#include "stl.h"
#include <iostream>

namespace py = pybind11;
using py_map = std::map<std::string, py::object>;
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
//PYTHON INSERT
void Table::Insert(py_map values) {
    
    //TODO: OVERRIDE FUNCTION PRBLEM FOR PYBIND11 build part
    //TODO: Checkout pybind11 module for cmake!

    py_map::iterator itr;
    int i = 1;

        for (itr = values.begin(); itr != values.end(); itr++){
            
            if (py::isinstance<py::str>(itr->second)) {
           std::cout << "THIS IS A STRING HAH \n";
            std::string o = py::cast<std::string>(itr->second);
            //std::cout << o << std::endl;
                }
            else if (py::isinstance<py::int_>(itr->second)) {
                std::cout << "THIS IS A INTEGER HAH \n";
           int o = py::cast<int>(itr->second);
           //int o = itr->second.cast<int>();
           std::cout << o << std::endl;
               }
            else if (py::isinstance<py::float_>(itr->second)) {
            std::cout << "THSI IS A FLOAT FLOAT HAH \n";
            float o = py::cast<float>(itr->second);
            //std::cout << o << std::endl;
            }
             //
            else{
                std::cout << "UNKNOWN TYPE \n";
            }       
        }
}

//C++ Insert
void Table::Insert(string_map values) {
//    for (auto item: values) {
//  auto key = item.first;
//  if (pybind11::str(key).check()) {
//    // do something on str.
 //     std::cout << "HEllo STRING \n";
//  } else if (pybind11::int_(key).check()) {
//      std::cout << "HELLO INT \n";
//  }
 // ...
//}
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
//void Table::Insert_v2(py::dict dict)
// Easily iterate over a dictionary using a C++11 range-based for loop */
//    void print_dict(py::dict dict) {
//        for (auto item : dict)
//            std::cout << "key: " << item.first << ", value=" << item.second << std::endl;
//    }
