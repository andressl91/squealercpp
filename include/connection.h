#ifndef CONNECTION
#define CONNECTION

#include <string>
#include <sqlite3.h>


class Connection {
    private:

    std::string db_path;

    public:
    sqlite3 *DB;
    Connection(std::string db_path);
    void query(std::string sql);
    void openDB();
    void closeDB();
    sqlite3 getConnection();

};

#endif
