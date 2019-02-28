#include <pybind11.h>
#include "table.h"
#include "database.h"
#include <string>

namespace py = pybind11;

PYBIND11_MODULE(sql_database, m) {
//PYBIND11_MODULE(table, m) {                             
     py::class_<Table>(m, "Table")
     .def(py::init<>())
     .def(py::init<std::string>())
     .def_readwrite("table_name", &Table::table_name);

   py::class_<DataBase>(m, "DataBase");
    // .def_readwrite("db_path", &DataBase::dbPath);
    // .def(py::init<std::string>());
 }                          


