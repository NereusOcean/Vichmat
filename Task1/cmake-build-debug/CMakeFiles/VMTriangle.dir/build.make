# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/nereus/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.8194.17/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/nereus/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.8194.17/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nereus/Vichmat/Task1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nereus/Vichmat/Task1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/VMTriangle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/VMTriangle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VMTriangle.dir/flags.make

CMakeFiles/VMTriangle.dir/main.cpp.o: CMakeFiles/VMTriangle.dir/flags.make
CMakeFiles/VMTriangle.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nereus/Vichmat/Task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/VMTriangle.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VMTriangle.dir/main.cpp.o -c /home/nereus/Vichmat/Task1/main.cpp

CMakeFiles/VMTriangle.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VMTriangle.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nereus/Vichmat/Task1/main.cpp > CMakeFiles/VMTriangle.dir/main.cpp.i

CMakeFiles/VMTriangle.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VMTriangle.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nereus/Vichmat/Task1/main.cpp -o CMakeFiles/VMTriangle.dir/main.cpp.s

CMakeFiles/VMTriangle.dir/back/Rb/RigidBody.cpp.o: CMakeFiles/VMTriangle.dir/flags.make
CMakeFiles/VMTriangle.dir/back/Rb/RigidBody.cpp.o: ../back/Rb/RigidBody.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nereus/Vichmat/Task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/VMTriangle.dir/back/Rb/RigidBody.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VMTriangle.dir/back/Rb/RigidBody.cpp.o -c /home/nereus/Vichmat/Task1/back/Rb/RigidBody.cpp

CMakeFiles/VMTriangle.dir/back/Rb/RigidBody.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VMTriangle.dir/back/Rb/RigidBody.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nereus/Vichmat/Task1/back/Rb/RigidBody.cpp > CMakeFiles/VMTriangle.dir/back/Rb/RigidBody.cpp.i

CMakeFiles/VMTriangle.dir/back/Rb/RigidBody.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VMTriangle.dir/back/Rb/RigidBody.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nereus/Vichmat/Task1/back/Rb/RigidBody.cpp -o CMakeFiles/VMTriangle.dir/back/Rb/RigidBody.cpp.s

# Object files for target VMTriangle
VMTriangle_OBJECTS = \
"CMakeFiles/VMTriangle.dir/main.cpp.o" \
"CMakeFiles/VMTriangle.dir/back/Rb/RigidBody.cpp.o"

# External object files for target VMTriangle
VMTriangle_EXTERNAL_OBJECTS =

VMTriangle: CMakeFiles/VMTriangle.dir/main.cpp.o
VMTriangle: CMakeFiles/VMTriangle.dir/back/Rb/RigidBody.cpp.o
VMTriangle: CMakeFiles/VMTriangle.dir/build.make
VMTriangle: CMakeFiles/VMTriangle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nereus/Vichmat/Task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable VMTriangle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VMTriangle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VMTriangle.dir/build: VMTriangle

.PHONY : CMakeFiles/VMTriangle.dir/build

CMakeFiles/VMTriangle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/VMTriangle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VMTriangle.dir/clean

CMakeFiles/VMTriangle.dir/depend:
	cd /home/nereus/Vichmat/Task1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nereus/Vichmat/Task1 /home/nereus/Vichmat/Task1 /home/nereus/Vichmat/Task1/cmake-build-debug /home/nereus/Vichmat/Task1/cmake-build-debug /home/nereus/Vichmat/Task1/cmake-build-debug/CMakeFiles/VMTriangle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/VMTriangle.dir/depend

