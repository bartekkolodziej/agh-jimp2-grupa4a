# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/bartek/Pobrane/clion-2016.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/bartek/Pobrane/clion-2016.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bartek/agh-jimp2-grupa4a

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bartek/agh-jimp2-grupa4a/cmake-build-debug

# Include any dependencies generated for this target.
include tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/depend.make

# Include the progress variables for this target.
include tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/progress.make

# Include the compile flags for this target's objects.
include tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/flags.make

tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.o: tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/flags.make
tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.o: ../tests/lib/gtest-1.8.0/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bartek/agh-jimp2-grupa4a/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.o"
	cd /home/bartek/agh-jimp2-grupa4a/cmake-build-debug/tests/lib/gtest-1.8.0/googlemock && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.o -c /home/bartek/agh-jimp2-grupa4a/tests/lib/gtest-1.8.0/googletest/src/gtest-all.cc

tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.i"
	cd /home/bartek/agh-jimp2-grupa4a/cmake-build-debug/tests/lib/gtest-1.8.0/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bartek/agh-jimp2-grupa4a/tests/lib/gtest-1.8.0/googletest/src/gtest-all.cc > CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.i

tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.s"
	cd /home/bartek/agh-jimp2-grupa4a/cmake-build-debug/tests/lib/gtest-1.8.0/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bartek/agh-jimp2-grupa4a/tests/lib/gtest-1.8.0/googletest/src/gtest-all.cc -o CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.s

tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.o.requires:

.PHONY : tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.o.requires

tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.o.provides: tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.o.requires
	$(MAKE) -f tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/build.make tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.o.provides.build
.PHONY : tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.o.provides

tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.o.provides.build: tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.o


tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o: tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/flags.make
tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o: ../tests/lib/gtest-1.8.0/googlemock/src/gmock-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bartek/agh-jimp2-grupa4a/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o"
	cd /home/bartek/agh-jimp2-grupa4a/cmake-build-debug/tests/lib/gtest-1.8.0/googlemock && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock_main.dir/src/gmock-all.cc.o -c /home/bartek/agh-jimp2-grupa4a/tests/lib/gtest-1.8.0/googlemock/src/gmock-all.cc

tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/src/gmock-all.cc.i"
	cd /home/bartek/agh-jimp2-grupa4a/cmake-build-debug/tests/lib/gtest-1.8.0/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bartek/agh-jimp2-grupa4a/tests/lib/gtest-1.8.0/googlemock/src/gmock-all.cc > CMakeFiles/gmock_main.dir/src/gmock-all.cc.i

tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/src/gmock-all.cc.s"
	cd /home/bartek/agh-jimp2-grupa4a/cmake-build-debug/tests/lib/gtest-1.8.0/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bartek/agh-jimp2-grupa4a/tests/lib/gtest-1.8.0/googlemock/src/gmock-all.cc -o CMakeFiles/gmock_main.dir/src/gmock-all.cc.s

tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.requires:

.PHONY : tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.requires

tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.provides: tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.requires
	$(MAKE) -f tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/build.make tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.provides.build
.PHONY : tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.provides

tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.provides.build: tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o


tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/flags.make
tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: ../tests/lib/gtest-1.8.0/googlemock/src/gmock_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bartek/agh-jimp2-grupa4a/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"
	cd /home/bartek/agh-jimp2-grupa4a/cmake-build-debug/tests/lib/gtest-1.8.0/googlemock && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.o -c /home/bartek/agh-jimp2-grupa4a/tests/lib/gtest-1.8.0/googlemock/src/gmock_main.cc

tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/src/gmock_main.cc.i"
	cd /home/bartek/agh-jimp2-grupa4a/cmake-build-debug/tests/lib/gtest-1.8.0/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bartek/agh-jimp2-grupa4a/tests/lib/gtest-1.8.0/googlemock/src/gmock_main.cc > CMakeFiles/gmock_main.dir/src/gmock_main.cc.i

tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/src/gmock_main.cc.s"
	cd /home/bartek/agh-jimp2-grupa4a/cmake-build-debug/tests/lib/gtest-1.8.0/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bartek/agh-jimp2-grupa4a/tests/lib/gtest-1.8.0/googlemock/src/gmock_main.cc -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.s

tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.requires:

.PHONY : tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.requires

tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.provides: tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.requires
	$(MAKE) -f tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/build.make tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.provides.build
.PHONY : tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.provides

tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.provides.build: tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o


# Object files for target gmock_main
gmock_main_OBJECTS = \
"CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.o" \
"CMakeFiles/gmock_main.dir/src/gmock-all.cc.o" \
"CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"

# External object files for target gmock_main
gmock_main_EXTERNAL_OBJECTS =

tests/lib/gtest-1.8.0/googlemock/libgmock_main.a: tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.o
tests/lib/gtest-1.8.0/googlemock/libgmock_main.a: tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o
tests/lib/gtest-1.8.0/googlemock/libgmock_main.a: tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
tests/lib/gtest-1.8.0/googlemock/libgmock_main.a: tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/build.make
tests/lib/gtest-1.8.0/googlemock/libgmock_main.a: tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bartek/agh-jimp2-grupa4a/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libgmock_main.a"
	cd /home/bartek/agh-jimp2-grupa4a/cmake-build-debug/tests/lib/gtest-1.8.0/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean_target.cmake
	cd /home/bartek/agh-jimp2-grupa4a/cmake-build-debug/tests/lib/gtest-1.8.0/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/build: tests/lib/gtest-1.8.0/googlemock/libgmock_main.a

.PHONY : tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/build

tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/requires: tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.o.requires
tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/requires: tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.requires
tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/requires: tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.requires

.PHONY : tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/requires

tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/clean:
	cd /home/bartek/agh-jimp2-grupa4a/cmake-build-debug/tests/lib/gtest-1.8.0/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean.cmake
.PHONY : tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/clean

tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/depend:
	cd /home/bartek/agh-jimp2-grupa4a/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bartek/agh-jimp2-grupa4a /home/bartek/agh-jimp2-grupa4a/tests/lib/gtest-1.8.0/googlemock /home/bartek/agh-jimp2-grupa4a/cmake-build-debug /home/bartek/agh-jimp2-grupa4a/cmake-build-debug/tests/lib/gtest-1.8.0/googlemock /home/bartek/agh-jimp2-grupa4a/cmake-build-debug/tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/lib/gtest-1.8.0/googlemock/CMakeFiles/gmock_main.dir/depend
