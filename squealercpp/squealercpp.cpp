#include "pybind11.h"
#include "stl.h"

#include "table.h"
#include "database.h"
#include "connection.h"
#include <string>

#include <map>
#include <vector>

namespace py = pybind11;
using py_map = std::map<std::string, py::object>;
using py_map_vector = std::vector<py_map>;
using string_map = std::map<std::string, std::string>;

//PYBIND11_MAKE_OPAQUE(py_map)
//PYBIND11_MAKE_OPAQUE(py_map_vector)


PYBIND11_MODULE(sql_database, m) {
    //py::bind_map<std::map<std::string, py::object>>(m, "MapStringObject")
    //py::bind_vector<py_map_vector>(m "MapStringObjectVector")

     py::class_<Table>(m, "Table")
     .def(py::init<>())
     .def(py::init<std::string, string_map, Connection *>())
     .def_readwrite("table_name", &Table::table_name)
     .def_readwrite("columns", &Table::columns)
     //.def("insert", &Table::Insert);
     .def("insert", (void (Table::*)(py_map *)) &Table::Insert, "Set the pet's age")
     .def("insert", (void (Table::*)(string_map)) &Table::Insert, "Set the pet's name")
     .def("bulk_insert", (void (Table::*)(py_map_vector *)) &Table::bulkInsert, "Set the pet's name")
     .def("bulk_insert_v2", (void (Table::*)(py_map_vector *)) &Table::bulkInsert_v2, "Set the pet's name");

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


