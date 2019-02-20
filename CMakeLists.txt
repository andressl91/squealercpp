cmake_minimum_required(VERSION 3.13)
project(squealercpp)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)
# cmake find_package doesn't support find_package
set(SQLITE_LIB_DIR /usr/lib)
find_library(sqlite3 NAMES sqlite3 PATHS ${SQLITE_LIB_DIR})
set(SQLITE_INDLUCE_DIR /usr/include)

include_directories(include)
add_library(libsquealer STATIC src/database.cpp src/connection.cpp)
target_compile_options(libsquealer PUBLIC -Wall -lsqlite3)

add_executable(hola src/main.cpp)
target_link_libraries(hola libsquealer sqlite3)
target_include_directories(hola PRIVATE {SQLITE_INDLUCE_DIR})

# tests
enable_testing()
add_executable(squealercpp_tests tests/main.cpp)
target_link_libraries(squealercpp_tests libsquealer Boost::unit_test_framework)
add_test(squealercpp_tests squealercpp_tests)



