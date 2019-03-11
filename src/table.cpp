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
    PreparedStatement(columns);
}

string_map Table::Features(){
    return columns;
}

template <typename T>
void Table::PreparedStatement(T values) {
    typename T::iterator itr;
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
    //std::cout << prepared_stmt << std::endl;

    statement.prepare(con, prepared_stmt);

}
//PYTHON INSERT
void Table::Insert(py_map * values) {

    //PreparedStatement(values);
    int i = 1;

    py_map::iterator itr;
    for (itr = values->begin(); itr != values->end(); itr++){
        
        if (py::isinstance<py::str>(itr->second)) {
        std::string o = py::cast<std::string>(itr->second);
        statement.bind(i, o);
        i++;
            }
        else if (py::isinstance<py::int_>(itr->second)) {
       int o = py::cast<int>(itr->second);
        statement.bind(i, o);
        i++;
           }
        else if (py::isinstance<py::float_>(itr->second)) {
        int o = py::cast<float>(itr->second);
        statement.bind(i, o);
        i++;
        }
         //
        else{
            std::cout << "UNKNOWN TYPE \n";
        }       
    }
        statement.step();
        
        //Reset Insert for next insert method call
        statement.reset();
}

//C++ Insert
void Table::Insert(string_map values) {
    //Define sql statement AND sqlite3_pepare_v2 ONCE
    PreparedStatement(values);
    string_map::iterator itr;
    int i = 1;
    for (itr = values.begin(); itr != values.end(); itr++){
        //std::cout << itr->first << " " << itr->second << "\n";
        statement.bind(i, itr->second);
        i++;
    }

    statement.step();
}

void Table::MultiPreparedStatement(const int n_inserts) {
    std::string sql_start = "BEGIN;";
    std::string sql = "INSERT INTO " + table_name + " (";
    string_map::iterator itr;
    for (itr = columns.begin(); itr != --columns.end(); itr++){
        sql += itr->first + ",";
    }
    sql += itr->first + ") ";
    
    sql += "VALUES (";

    for (itr = columns.begin(); itr != --columns.end(); itr++){
        sql += "?, ";
    }
    sql += "?);";

    prepared_stmt = sql;
    for(int i = 1; i < n_inserts; i++)
        prepared_stmt += sql;

    prepared_stmt = "BEGIN TRANSACTION;" + prepared_stmt +  "END TRANSACTION;";
    std::cout << prepared_stmt << std::endl;

    multi_statement.prepare(con, prepared_stmt);
}

void Table::bulkInsert(py_map_vector * values){

    int i = 1;
    const int bulk_size = values->size();
    
    for (auto val : *values) {
        Insert(&val);
    }
    //for (itr_vec = values.begin(); itr_vec != values.end(); itr_vec++) {
    /**
    //std::cout << bulk_size << std::endl;
    //MultiPreparedStatement(bulk_size);
    py_map * value;
    for (auto val : *values) {

        value = &val;
        py_map::iterator itr;
        for (itr = value->begin(); itr != value->end(); itr++){
            
            if (py::isinstance<py::str>(itr->second)) {
            std::string o = py::cast<std::string>(itr->second);
            std::cout << o + " STRING \n";
            multi_statement.bind(i, o);
            i++;
                }
            else if (py::isinstance<py::int_>(itr->second)) {
           int o = py::cast<int>(itr->second);
            std::cout << o + " INT  \n";
            multi_statement.bind(i, o);
            i++;
               }
            else if (py::isinstance<py::float_>(itr->second)) {
            int o = py::cast<float>(itr->second);
            multi_statement.bind(i, o);
            i++;
            }
             //
            else{
                std::cout << "UNKNOWN TYPE \n";
            }       
        }
    } 
        multi_statement.step();
        multi_statement.reset();
        */
}


void Table::bulkInsert_v2(py_map_vector * values){

    int i = 1;
    const int bulk_size = values->size();
    
    for (auto val : *values) {
    
    //std::cout << bulk_size << std::endl;
    //MultiPreparedStatement(bulk_size);
    py_map * value;
    for (auto val : *values) {

        value = &val;
        py_map::iterator itr;
        for (itr = value->begin(); itr != value->end(); itr++){
            
            if (py::isinstance<py::str>(itr->second)) {
            std::string o = py::cast<std::string>(itr->second);
            std::cout << o + " STRING \n";
            multi_statement.bind(i, o);
            i++;
                }
            else if (py::isinstance<py::int_>(itr->second)) {
           int o = py::cast<int>(itr->second);
            std::cout << o + " INT  \n";
            multi_statement.bind(i, o);
            i++;
               }
            else if (py::isinstance<py::float_>(itr->second)) {
            int o = py::cast<float>(itr->second);
            multi_statement.bind(i, o);
            i++;
            }
             //
            else{
                std::cout << "UNKNOWN TYPE \n";
            }       
        }
    } 
        multi_statement.step();
        multi_statement.reset();
}
