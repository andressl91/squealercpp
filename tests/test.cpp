#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(dummy) {
    BOOST_CHECK_EQUAL(1 + 1, 2);
}
