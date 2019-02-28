table:
	#g++ -O3 -Wall -shared -std=c++11 -fPIC `python3.7 -m pybind11 --includes` squealercpp.cpp -o sql_database`python3-config --extension-suffix` -I pybind11/include/pybind11/ -I../include/ -L ../build -lsquealer
	g++ -Wall -shared -std=c++11 -fPIC `python3.7 -m pybind11 --includes` squealercpp.cpp -o sql_database`python3-config --extension-suffix` -I pybind11/include/pybind11/ -I../include/ -L ../build -lsquealer

test_table:
	g++ -Wall -shared -std=c++11 -fPIC `python3.7 -m pybind11 --includes` squealercpp.cpp -o sql_database`python3-config --extension-suffix` -I pybind11/include/pybind11/ -I../include/ -L ../build -lsquealer -lsqlite3
