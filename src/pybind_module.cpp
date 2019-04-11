#include "pybind_module.h"


void PybindTable::Insert(py_map * values) {

    int i = 1;
    py_map::iterator itr;
    for (itr = values->begin(); itr != values->end(); itr++){
        
        if (py::isinstance<py::str>(itr->second)) {
        const std::string o = py::cast<std::string>(itr->second);
        statement.bind(i, o);
        i++;
            }
        else if (py::isinstance<py::int_>(itr->second)) {
        const int o = py::cast<int>(itr->second);
        statement.bind(i, o);
        i++;
           }
        else if (py::isinstance<py::float_>(itr->second)) {
        const float o = py::cast<float>(itr->second);
        statement.bind(i, o);
        i++;
        }
        else{
            std::cout << "UNKNOWN TYPE \n";
        }       
    }
        statement.step();
        //Reset Insert for next insert method call
        statement.reset();
}

void PybindTable::bulkInsert(const py_map_vector * values){

    int i = 1;
    const int bulk_size = values->size();
    
    for (auto val : *values) {
        Insert(&val);
    }
}


void PybindTable::bulkInsert_v2(const py_map_vector * values){

    char *err_message = 0;

    con->openDB();
    int rc = sqlite3_exec(con->DB, "BEGIN TRANSACTION", NULL, NULL, &err_message);

    int i;
    py_map * value;
    for (auto val : *values) {

        value = &val;
        py_map::iterator itr;
        i = 1;
        for (itr = value->begin(); itr != value->end(); itr++){
            
            if (py::isinstance<py::str>(itr->second)) {
            const std::string o = py::cast<std::string>(itr->second);
            statement.bind(i, o);
            i++;
                }
            else if (py::isinstance<py::float_>(itr->second)) {
            const float o = py::cast<float>(itr->second);
            statement.bind(i, o);
            i++;
            }
            else if (py::isinstance<py::int_>(itr->second)) {
           const float o = py::cast<int>(itr->second);
            statement.bind(i, o);
            i++;
               }
            else{
                std::cout << "UNKNOWN TYPE \n";
            }       

        }
        statement.step();
        statement.reset();
    } 
    rc = sqlite3_exec(con->DB, "COMMIT TRANSACTION", NULL, NULL, &err_message);
    // include in statement class, with cleanup for new stmt
    sqlite3_finalize(statement.insert_stmt);
    con->closeDB();
   
}
