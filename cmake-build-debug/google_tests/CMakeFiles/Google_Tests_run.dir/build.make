# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /mnt/c/Users/kysar/CLionProjects/long_arithmetic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/kysar/CLionProjects/long_arithmetic/cmake-build-debug

# Include any dependencies generated for this target.
include google_tests/CMakeFiles/Google_Tests_run.dir/depend.make

# Include the progress variables for this target.
include google_tests/CMakeFiles/Google_Tests_run.dir/progress.make

# Include the compile flags for this target's objects.
include google_tests/CMakeFiles/Google_Tests_run.dir/flags.make

google_tests/CMakeFiles/Google_Tests_run.dir/Test.cpp.o: google_tests/CMakeFiles/Google_Tests_run.dir/flags.make
google_tests/CMakeFiles/Google_Tests_run.dir/Test.cpp.o: ../google_tests/Test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/kysar/CLionProjects/long_arithmetic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object google_tests/CMakeFiles/Google_Tests_run.dir/Test.cpp.o"
	cd /mnt/c/Users/kysar/CLionProjects/long_arithmetic/cmake-build-debug/google_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Google_Tests_run.dir/Test.cpp.o -c /mnt/c/Users/kysar/CLionProjects/long_arithmetic/google_tests/Test.cpp

google_tests/CMakeFiles/Google_Tests_run.dir/Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_Tests_run.dir/Test.cpp.i"
	cd /mnt/c/Users/kysar/CLionProjects/long_arithmetic/cmake-build-debug/google_tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/kysar/CLionProjects/long_arithmetic/google_tests/Test.cpp > CMakeFiles/Google_Tests_run.dir/Test.cpp.i

google_tests/CMakeFiles/Google_Tests_run.dir/Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_Tests_run.dir/Test.cpp.s"
	cd /mnt/c/Users/kysar/CLionProjects/long_arithmetic/cmake-build-debug/google_tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/kysar/CLionProjects/long_arithmetic/google_tests/Test.cpp -o CMakeFiles/Google_Tests_run.dir/Test.cpp.s

# Object files for target Google_Tests_run
Google_Tests_run_OBJECTS = \
"CMakeFiles/Google_Tests_run.dir/Test.cpp.o"

# External object files for target Google_Tests_run
Google_Tests_run_EXTERNAL_OBJECTS =

google_tests/Google_Tests_run: google_tests/CMakeFiles/Google_Tests_run.dir/Test.cpp.o
google_tests/Google_Tests_run: google_tests/CMakeFiles/Google_Tests_run.dir/build.make
google_tests/Google_Tests_run: LongArithmetic/libLongArithmetic.a
google_tests/Google_Tests_run: lib/libgtestd.a
google_tests/Google_Tests_run: lib/libgtest_maind.a
google_tests/Google_Tests_run: lib/libgtestd.a
google_tests/Google_Tests_run: google_tests/CMakeFiles/Google_Tests_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/kysar/CLionProjects/long_arithmetic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Google_Tests_run"
	cd /mnt/c/Users/kysar/CLionProjects/long_arithmetic/cmake-build-debug/google_tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Google_Tests_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
google_tests/CMakeFiles/Google_Tests_run.dir/build: google_tests/Google_Tests_run

.PHONY : google_tests/CMakeFiles/Google_Tests_run.dir/build

google_tests/CMakeFiles/Google_Tests_run.dir/clean:
	cd /mnt/c/Users/kysar/CLionProjects/long_arithmetic/cmake-build-debug/google_tests && $(CMAKE_COMMAND) -P CMakeFiles/Google_Tests_run.dir/cmake_clean.cmake
.PHONY : google_tests/CMakeFiles/Google_Tests_run.dir/clean

google_tests/CMakeFiles/Google_Tests_run.dir/depend:
	cd /mnt/c/Users/kysar/CLionProjects/long_arithmetic/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/kysar/CLionProjects/long_arithmetic /mnt/c/Users/kysar/CLionProjects/long_arithmetic/google_tests /mnt/c/Users/kysar/CLionProjects/long_arithmetic/cmake-build-debug /mnt/c/Users/kysar/CLionProjects/long_arithmetic/cmake-build-debug/google_tests /mnt/c/Users/kysar/CLionProjects/long_arithmetic/cmake-build-debug/google_tests/CMakeFiles/Google_Tests_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : google_tests/CMakeFiles/Google_Tests_run.dir/depend

