#ifndef STATEMENT
#define STATEMENT

#include <sqlite3.h>
#include <string>
#include "connection.h"
//#include "pybind11.h"
//TODO: Make include to pybind11.h work i CMAKE
//THAT PART AFTER -PIC

class Statement {

    public:
    Connection * connection;
    sqlite3_stmt *insert_stmt;
    Statement();
    void prepare(Connection * con, std::string sql);
    void bind(int const index, int const value);
    void bind(int const index, float const value);
    void bind(int const index, const std::string value);
    void step();
    void reset();

};

#endif
