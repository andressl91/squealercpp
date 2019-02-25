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
};


#endif
