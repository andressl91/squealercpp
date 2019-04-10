#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>

#include <string>
#include "table.h"
#include "database.h"
#include "sqltypes.h"


BOOST_AUTO_TEST_CASE(sqltypes) {
    SqlType sqltype; 
    BOOST_CHECK(sqltype.NONE == "NONE");
    BOOST_CHECK(sqltype.INTEGER == "INTEGER");
    BOOST_CHECK(sqltype.REAL == "REAL");
    BOOST_CHECK(sqltype.TEXT == "TEXT");
    BOOST_CHECK(sqltype.BLOB == "BLOB");


}

BOOST_AUTO_TEST_CASE(TableOperations){
    string_map feat;
    SqlType s_typ;
        
    std::string name = "createtable.db";
    feat["ID"] = s_typ.INTEGER;
    feat["NAME"] = s_typ.TEXT;
    std::string table_n = "COMPANY";

    DataBase database(name);
    BOOST_CHECK(database.dbPath == "createtable.db");
    BOOST_CHECK(database.tables.size() == 0);
    database.createTable(table_n, feat);
    BOOST_CHECK(database.tables.size() == 1);
    BOOST_CHECK(database.tables.count("COMPANY") == 1);

    auto tbl_find = database.tables.find("COMPANY");

    Table tbl = tbl_find->second;
    BOOST_CHECK_EQUAL(tbl.table_name, "COMPANY");
    BOOST_CHECK_EQUAL(tbl.columns["ID"], s_typ.INTEGER);
    BOOST_CHECK_EQUAL(tbl.columns["NAME"], s_typ.TEXT);

    // Check that overwrite flag creates new table with new columns and types
    feat.clear();
    feat["JAB"] = s_typ.TEXT;
    feat["JIB"] = s_typ.INTEGER;
    database.createTable(table_n, feat, true);
    BOOST_CHECK(database.tables.size() == 1);
    BOOST_CHECK(database.tables.count("COMPANY") == 1);
    auto tbl_find_overwrite = database.tables.find("COMPANY");

    tbl = tbl_find_overwrite->second;
    BOOST_CHECK_EQUAL(tbl.table_name, "COMPANY");
    BOOST_CHECK_EQUAL(tbl.columns.size(), 2);
    BOOST_CHECK_EQUAL(tbl.columns["JAB"], s_typ.TEXT);
    BOOST_CHECK_EQUAL(tbl.columns["JIB"], s_typ.INTEGER);

    BOOST_CHECK_EQUAL(tbl.columns["JAB"], tbl.Features()["JAB"]);

    database.dropTable(table_n);
    BOOST_CHECK(database.tables.size() == 0);

}


BOOST_AUTO_TEST_CASE(TableInsert){
    string_map feat;
    SqlType s_typ;
        
    std::string name = "createtable.db";
    feat["ID"] = s_typ.INTEGER;
    feat["NAME"] = s_typ.TEXT;
    std::string table_n = "COMPANY";

    DataBase database(name);
    database.createTable(table_n, feat);
        
    std::map<std::string, std::string> int_map;
    int_map["ID"] = "ROBOT";
    int_map["NAME"] = "R2D2";

    auto tbl_find = database.tables.find("COMPANY");

    Table tbl = tbl_find->second;
    tbl.Insert(int_map);
 } 







