#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>

#include <string>
#include "table.h"
#include "database.h"

BOOST_AUTO_TEST_CASE(fetchtables) {

    std::string name = "example.db";

    DataBase database(name);
    BOOST_CHECK(database.dbPath == "example.db");

    BOOST_CHECK(database.tables.size() == 0);
    database.fetchTables();
    BOOST_CHECK(database.tables.size() == 1);
    BOOST_CHECK(database.tables.count("COMPANY") == 1);

    auto tbl_find = database.tables.find("COMPANY");

    Table tbl = tbl_find->second;
    BOOST_CHECK_EQUAL(tbl.table_name, "COMPANY");



}


BOOST_AUTO_TEST_CASE(table) {
    Table tabl = Table("test");
    BOOST_CHECK_EQUAL(tabl.table_name, "test");
    BOOST_CHECK_EQUAL(1 + 1, 2);
}

