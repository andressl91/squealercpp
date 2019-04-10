cmake_minimum_required(VERSION 3.13)
project(squealercpp)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

# cmake find_package doesn't support find_package for sqlite
#set(PYBIND_LIB_DIR /usr/lib)
#find_library(pybind NAMES pybind PATHS ${PYBIND_LIB_DIR})
set(PYBIND_INDLUCE_DIR include/pybind11/include/pybind11/)

set(SQLITE_LIB_DIR /usr/lib)
find_library(sqlite3 NAMES sqlite3 PATHS ${SQLITE_LIB_DIR})
set(SQLITE_INDLUCE_DIR /usr/include)

# PYTHON FOR PYBIND11
include_directories(include ${PYBIND_INDLUCE_DIR} /usr/include/python3.7m)
add_library(squealer STATIC src/database.cpp src/connection.cpp src/table.cpp src/sqltypes.cpp src/statement.cpp src/pybind_module.cpp)
target_compile_options(squealer PUBLIC -Wall -shared -fPIC -lsqlite3)


add_executable(squeal src/main.cpp)
target_link_libraries(squeal squealer sqlite3 python3.7m)
target_include_directories(squeal PRIVATE {SQLITE_INDLUCE_DIR} {PYBIND_INDLUCE_DIR} /usr/include/python3.7m /home/jackal/.local/include/python3.7m)

# tests
enable_testing()
add_executable(test_squealer tests/main.cpp)
target_link_libraries(test_squealer squealer Boost::unit_test_framework sqlite3 python3.7m)
target_include_directories(squeal PRIVATE {SQLITE_INDLUCE_DIR} {PYBIND_INDLUCE_DIR} /usr/include/python3.7m /home/jackal/.local/include/python3.7m)
add_test(test_squealer test_squealer)



