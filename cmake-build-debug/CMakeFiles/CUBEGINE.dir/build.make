# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\nbenc\CLionProjects\CUBEGINE

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\nbenc\CLionProjects\CUBEGINE\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CUBEGINE.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CUBEGINE.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CUBEGINE.dir/flags.make

CMakeFiles/CUBEGINE.dir/main.cpp.obj: CMakeFiles/CUBEGINE.dir/flags.make
CMakeFiles/CUBEGINE.dir/main.cpp.obj: CMakeFiles/CUBEGINE.dir/includes_CXX.rsp
CMakeFiles/CUBEGINE.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\nbenc\CLionProjects\CUBEGINE\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CUBEGINE.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CUBEGINE.dir\main.cpp.obj -c C:\Users\nbenc\CLionProjects\CUBEGINE\main.cpp

CMakeFiles/CUBEGINE.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CUBEGINE.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\nbenc\CLionProjects\CUBEGINE\main.cpp > CMakeFiles\CUBEGINE.dir\main.cpp.i

CMakeFiles/CUBEGINE.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CUBEGINE.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\nbenc\CLionProjects\CUBEGINE\main.cpp -o CMakeFiles\CUBEGINE.dir\main.cpp.s

# Object files for target CUBEGINE
CUBEGINE_OBJECTS = \
"CMakeFiles/CUBEGINE.dir/main.cpp.obj"

# External object files for target CUBEGINE
CUBEGINE_EXTERNAL_OBJECTS =

CUBEGINE.exe: CMakeFiles/CUBEGINE.dir/main.cpp.obj
CUBEGINE.exe: CMakeFiles/CUBEGINE.dir/build.make
CUBEGINE.exe: dependencies/glfw/src/libglfw3.a
CUBEGINE.exe: CMakeFiles/CUBEGINE.dir/linklibs.rsp
CUBEGINE.exe: CMakeFiles/CUBEGINE.dir/objects1.rsp
CUBEGINE.exe: CMakeFiles/CUBEGINE.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\nbenc\CLionProjects\CUBEGINE\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CUBEGINE.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CUBEGINE.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CUBEGINE.dir/build: CUBEGINE.exe

.PHONY : CMakeFiles/CUBEGINE.dir/build

CMakeFiles/CUBEGINE.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CUBEGINE.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CUBEGINE.dir/clean

CMakeFiles/CUBEGINE.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\nbenc\CLionProjects\CUBEGINE C:\Users\nbenc\CLionProjects\CUBEGINE C:\Users\nbenc\CLionProjects\CUBEGINE\cmake-build-debug C:\Users\nbenc\CLionProjects\CUBEGINE\cmake-build-debug C:\Users\nbenc\CLionProjects\CUBEGINE\cmake-build-debug\CMakeFiles\CUBEGINE.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CUBEGINE.dir/depend

