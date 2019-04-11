#ifndef PYBIND_MODULE
#define PYBIND_MODUEL

#include <iostream>
#include "pybind11.h"
#include "table.h"
#include "stl.h"
namespace py = pybind11;
using py_map = std::map<std::string, py::object>;

class PybindTable : public Table {

    public:
        int a = 2;
    void Insert(py_map * values);
    void bulkInsert(const py_map_vector * values);
    void bulkInsert_v2(const py_map_vector * values);
    void bulkInsert_v3(const py_map_vector * values);
};
#endif
