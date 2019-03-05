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
    BOOST_CHECK(sqltype.FLOAT == "FLOAT");
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
    //database.fetchTables();
    BOOST_CHECK(database.tables.size() == 1);
    BOOST_CHECK(database.tables.count("COMPANY") == 1);

    auto tbl_find = database.tables.find("COMPANY");

    Table tbl = tbl_find->second;
    BOOST_CHECK_EQUAL(tbl.table_name, "COMPANY");
    BOOST_CHECK_EQUAL(tbl.columns["ID"], s_typ.INTEGER);
    BOOST_CHECK_EQUAL(tbl.columns["NAME"], s_typ.TEXT);
}



BOOST_AUTO_TEST_CASE(table) {
    Table tabl = Table("test");
    BOOST_CHECK_EQUAL(tabl.table_name, "test");
}

