#ifndef CONNECTION
#define CONNECTION

#include <string>
#include <sqlite3.h>


class Connection {
    public:
    std::string db_path;
    sqlite3 *DB;
    Connection(std::string sql_db_path);
    void query(std::string sql);
    void openDB();
    void closeDB();
    sqlite3 getConnection();

};

#endif
