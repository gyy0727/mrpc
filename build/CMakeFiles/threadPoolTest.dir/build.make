# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/cmake-3.27.7/cmake-3.27.7-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.27.7/cmake-3.27.7-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/muqiu0614/桌面/threadPool

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/muqiu0614/桌面/build

# Include any dependencies generated for this target.
include CMakeFiles/threadPoolTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/threadPoolTest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/threadPoolTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/threadPoolTest.dir/flags.make

CMakeFiles/threadPoolTest.dir/src/Thread.cc.o: CMakeFiles/threadPoolTest.dir/flags.make
CMakeFiles/threadPoolTest.dir/src/Thread.cc.o: /home/muqiu0614/桌面/threadPool/src/Thread.cc
CMakeFiles/threadPoolTest.dir/src/Thread.cc.o: CMakeFiles/threadPoolTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/muqiu0614/桌面/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/threadPoolTest.dir/src/Thread.cc.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/threadPoolTest.dir/src/Thread.cc.o -MF CMakeFiles/threadPoolTest.dir/src/Thread.cc.o.d -o CMakeFiles/threadPoolTest.dir/src/Thread.cc.o -c /home/muqiu0614/桌面/threadPool/src/Thread.cc

CMakeFiles/threadPoolTest.dir/src/Thread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/threadPoolTest.dir/src/Thread.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/桌面/threadPool/src/Thread.cc > CMakeFiles/threadPoolTest.dir/src/Thread.cc.i

CMakeFiles/threadPoolTest.dir/src/Thread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/threadPoolTest.dir/src/Thread.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/桌面/threadPool/src/Thread.cc -o CMakeFiles/threadPoolTest.dir/src/Thread.cc.s

CMakeFiles/threadPoolTest.dir/src/ThreadPool.cc.o: CMakeFiles/threadPoolTest.dir/flags.make
CMakeFiles/threadPoolTest.dir/src/ThreadPool.cc.o: /home/muqiu0614/桌面/threadPool/src/ThreadPool.cc
CMakeFiles/threadPoolTest.dir/src/ThreadPool.cc.o: CMakeFiles/threadPoolTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/muqiu0614/桌面/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/threadPoolTest.dir/src/ThreadPool.cc.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/threadPoolTest.dir/src/ThreadPool.cc.o -MF CMakeFiles/threadPoolTest.dir/src/ThreadPool.cc.o.d -o CMakeFiles/threadPoolTest.dir/src/ThreadPool.cc.o -c /home/muqiu0614/桌面/threadPool/src/ThreadPool.cc

CMakeFiles/threadPoolTest.dir/src/ThreadPool.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/threadPoolTest.dir/src/ThreadPool.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/桌面/threadPool/src/ThreadPool.cc > CMakeFiles/threadPoolTest.dir/src/ThreadPool.cc.i

CMakeFiles/threadPoolTest.dir/src/ThreadPool.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/threadPoolTest.dir/src/ThreadPool.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/桌面/threadPool/src/ThreadPool.cc -o CMakeFiles/threadPoolTest.dir/src/ThreadPool.cc.s

CMakeFiles/threadPoolTest.dir/src/main.cc.o: CMakeFiles/threadPoolTest.dir/flags.make
CMakeFiles/threadPoolTest.dir/src/main.cc.o: /home/muqiu0614/桌面/threadPool/src/main.cc
CMakeFiles/threadPoolTest.dir/src/main.cc.o: CMakeFiles/threadPoolTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/muqiu0614/桌面/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/threadPoolTest.dir/src/main.cc.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/threadPoolTest.dir/src/main.cc.o -MF CMakeFiles/threadPoolTest.dir/src/main.cc.o.d -o CMakeFiles/threadPoolTest.dir/src/main.cc.o -c /home/muqiu0614/桌面/threadPool/src/main.cc

CMakeFiles/threadPoolTest.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/threadPoolTest.dir/src/main.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muqiu0614/桌面/threadPool/src/main.cc > CMakeFiles/threadPoolTest.dir/src/main.cc.i

CMakeFiles/threadPoolTest.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/threadPoolTest.dir/src/main.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muqiu0614/桌面/threadPool/src/main.cc -o CMakeFiles/threadPoolTest.dir/src/main.cc.s

# Object files for target threadPoolTest
threadPoolTest_OBJECTS = \
"CMakeFiles/threadPoolTest.dir/src/Thread.cc.o" \
"CMakeFiles/threadPoolTest.dir/src/ThreadPool.cc.o" \
"CMakeFiles/threadPoolTest.dir/src/main.cc.o"

# External object files for target threadPoolTest
threadPoolTest_EXTERNAL_OBJECTS =

/home/muqiu0614/桌面/threadPool/bin/threadPoolTest: CMakeFiles/threadPoolTest.dir/src/Thread.cc.o
/home/muqiu0614/桌面/threadPool/bin/threadPoolTest: CMakeFiles/threadPoolTest.dir/src/ThreadPool.cc.o
/home/muqiu0614/桌面/threadPool/bin/threadPoolTest: CMakeFiles/threadPoolTest.dir/src/main.cc.o
/home/muqiu0614/桌面/threadPool/bin/threadPoolTest: CMakeFiles/threadPoolTest.dir/build.make
/home/muqiu0614/桌面/threadPool/bin/threadPoolTest: CMakeFiles/threadPoolTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/muqiu0614/桌面/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable /home/muqiu0614/桌面/threadPool/bin/threadPoolTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/threadPoolTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/threadPoolTest.dir/build: /home/muqiu0614/桌面/threadPool/bin/threadPoolTest
.PHONY : CMakeFiles/threadPoolTest.dir/build

CMakeFiles/threadPoolTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/threadPoolTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/threadPoolTest.dir/clean

CMakeFiles/threadPoolTest.dir/depend:
	cd /home/muqiu0614/桌面/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/muqiu0614/桌面/threadPool /home/muqiu0614/桌面/threadPool /home/muqiu0614/桌面/build /home/muqiu0614/桌面/build /home/muqiu0614/桌面/build/CMakeFiles/threadPoolTest.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/threadPoolTest.dir/depend

