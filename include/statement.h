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
    void bind2(int *  index, int * value);
    void bind2(int *  index, float * value);
    void bind2(int *  index, std::string * value);
    void bind(const int  index, const int value);
    void bind(const int index, const float value);
    void bind(const int index, const std::string value);
    void step();
    void reset();

};

#endif
