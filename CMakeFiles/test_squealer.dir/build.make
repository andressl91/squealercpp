# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jackal/.virtenv/squealercpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jackal/.virtenv/squealercpp

# Include any dependencies generated for this target.
include CMakeFiles/test_squealer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_squealer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_squealer.dir/flags.make

CMakeFiles/test_squealer.dir/tests/main.cpp.o: CMakeFiles/test_squealer.dir/flags.make
CMakeFiles/test_squealer.dir/tests/main.cpp.o: tests/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jackal/.virtenv/squealercpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_squealer.dir/tests/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_squealer.dir/tests/main.cpp.o -c /home/jackal/.virtenv/squealercpp/tests/main.cpp

CMakeFiles/test_squealer.dir/tests/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_squealer.dir/tests/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jackal/.virtenv/squealercpp/tests/main.cpp > CMakeFiles/test_squealer.dir/tests/main.cpp.i

CMakeFiles/test_squealer.dir/tests/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_squealer.dir/tests/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jackal/.virtenv/squealercpp/tests/main.cpp -o CMakeFiles/test_squealer.dir/tests/main.cpp.s

# Object files for target test_squealer
test_squealer_OBJECTS = \
"CMakeFiles/test_squealer.dir/tests/main.cpp.o"

# External object files for target test_squealer
test_squealer_EXTERNAL_OBJECTS =

test_squealer: CMakeFiles/test_squealer.dir/tests/main.cpp.o
test_squealer: CMakeFiles/test_squealer.dir/build.make
test_squealer: liblibsquealer.a
test_squealer: /usr/lib/libboost_unit_test_framework.a
test_squealer: CMakeFiles/test_squealer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jackal/.virtenv/squealercpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_squealer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_squealer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_squealer.dir/build: test_squealer

.PHONY : CMakeFiles/test_squealer.dir/build

CMakeFiles/test_squealer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_squealer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_squealer.dir/clean

CMakeFiles/test_squealer.dir/depend:
	cd /home/jackal/.virtenv/squealercpp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jackal/.virtenv/squealercpp /home/jackal/.virtenv/squealercpp /home/jackal/.virtenv/squealercpp /home/jackal/.virtenv/squealercpp /home/jackal/.virtenv/squealercpp/CMakeFiles/test_squealer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_squealer.dir/depend

