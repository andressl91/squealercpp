#ifndef SQLTYPES
#define SQLTYPES

#include <string>
struct SqlType {
    public:
    const std::string NONE = "NONE";
    const std::string INTEGER = "INTEGER";
    const std::string FLOAT = "FLOAT";
    const std::string TEXT = "TEXT";
    const std::string BLOB = "BLOB";

    const std::string NOT_NULL = "NOT NULL";
    const std::string PRIMARY_KEY = "PRIMARY KEY";
};


#endif
