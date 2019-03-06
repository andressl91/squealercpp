#include <sqlite3.h>
#include <string>
#include "connection.h"

class Statement {

    public:
    sqlite3_stmt *insert_stmt;
    Statement();
    void prepare(Connection * con, std::string * sql);
    void bind(int const index, int const value);
    void step();
    void reset();

};
