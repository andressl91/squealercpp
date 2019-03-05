#include <pybind11.h>
#include <stl.h>

#include "table.h"
#include "database.h"
#include "connection.h"
#include <string>

namespace py = pybind11;

PYBIND11_MODULE(sql_database, m) {
//PYBIND11_MODULE(table, m) {                             
     py::class_<Table>(m, "Table")
     .def(py::init<>())
     .def(py::init<std::string>())
     .def_readwrite("table_name", &Table::table_name)
     .def_readwrite("columns", &Table::columns);

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

    // .def_readwrite("db_path", &DataBase::dbPath);
    // .def(py::init<std::string>());
 }                          


