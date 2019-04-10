#include "table.h"
#include "pybind11.h"
#include "stl.h"
#include <iostream>

namespace py = pybind11;
using py_map = std::map<std::string, py::object>;
using string_map = std::map<std::string, std::string>;
using float_map = std::map<std::string, float>;

Table::Table() 
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
    // Can basicly take any map, as long as key is string
    typename T::iterator itr;
    std::string sql = "INSERT INTO " + table_name + " (";
    for (itr = values.begin(); itr != --values.end(); itr++){
        sql += itr->first + ",";
    }
    sql += itr->first + ") ";
    sql += "VALUES (";

    int i = 1;
    for (itr = values.begin(); itr != --values.end(); itr++){
        sql += "?" + std::to_string(i)  + ", ";
        i++;
    }
    sql += "?" + std::to_string(i) + ")";
    prepared_stmt = sql;
    statement.prepare(con, prepared_stmt);

}

//C++ Insert
void Table::Insert(string_map values) {
    //PreparedStatement(values);
    string_map::iterator itr;
    int i = 1;
    for (itr = values.begin(); itr != values.end(); itr++){

        statement.bind(i, itr->second);
        i++;
    }

    statement.step();
    statement.reset();
}
/*
void Table::Insert(string_map values) {
    //PreparedStatement(values);
    string_map::iterator itr;
    int i = 1;
    for (itr = values.begin(); itr != values.end(); itr++){

        statement.bind(i, itr->second);
        i++;
    }

    statement.step();
    statement.reset();
} */

template <typename T>
void Table::InsertV3(const T values) {
    con->openDB();
    //PreparedStatement(values);
    typename T::iterator itr;
    int i = 1;
    std::cout << "HERE \n";
    for (itr = values.begin(); itr != values.end(); itr++){
        //statement.bind2(&i, &itr->second);
        std::cout << i << " " << itr->second << std::endl;
        statement.bind(i, itr->second);
        i++;
    }

    statement.step();
    statement.reset();
  //  sqlite3_finalize(statement.insert_stmt);
    con->closeDB();
}


void Table::MultiPreparedStatement(const int n_inserts) {
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

