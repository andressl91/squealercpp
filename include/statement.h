#ifndef STATEMENT
#define STATEMENT

#include <sqlite3.h>
#include <string>
#include "connection.h"

class Statement {

    public:
    Connection * connection;
    sqlite3_stmt *insert_stmt;
    Statement();
    void prepare(Connection * con, std::string sql);
    void bind(int const index, int const value);
    void bind(int const index, std::string value);
    void step();
    void reset();

};

#endif
