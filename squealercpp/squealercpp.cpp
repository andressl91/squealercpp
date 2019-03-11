#include "pybind11.h"
#include "stl.h"

#include "table.h"
#include "database.h"
#include "connection.h"
#include <string>

#include <map>

namespace py = pybind11;
using py_map = std::map<std::string, py::object>;
using string_map = std::map<std::string, std::string>;

PYBIND11_MODULE(sql_database, m) {
//PYBIND11_MODULE(table, m) {                             
     py::class_<Table>(m, "Table")
     .def(py::init<>())
     .def(py::init<std::string>())
     .def_readwrite("table_name", &Table::table_name)
     .def_readwrite("columns", &Table::columns)
     //.def("insert", &Table::Insert);
     .def("insert", (void (Table::*)(py_map *)) &Table::Insert, "Set the pet's age")
     .def("insert", (void (Table::*)(string_map)) &Table::Insert, "Set the pet's name");

   py::class_<DataBase>(m, "DataBase")
    .def(py::init<std::string>())
    .def_readwrite("db_path", &DataBase::dbPath)
    .def_readwrite("tables", &DataBase::tables)
    .def("fetch_tables", &DataBase::fetchTables)
    .def("create_table", &DataBase::createTable,
       py::arg("table_name"), py::arg("features"), py::arg("overwrite") = false);

   py::class_<Connection>(m, "Connection")
    .def(py::init<std::string>())
    .def_readwrite("db_path", &Connection::db_path);

 }                          


