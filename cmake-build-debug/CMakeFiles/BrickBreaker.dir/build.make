# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\BrickBreaker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\BrickBreaker\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BrickBreaker.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BrickBreaker.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BrickBreaker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BrickBreaker.dir/flags.make

CMakeFiles/BrickBreaker.dir/main.cpp.obj: CMakeFiles/BrickBreaker.dir/flags.make
CMakeFiles/BrickBreaker.dir/main.cpp.obj: CMakeFiles/BrickBreaker.dir/includes_CXX.rsp
CMakeFiles/BrickBreaker.dir/main.cpp.obj: ../main.cpp
CMakeFiles/BrickBreaker.dir/main.cpp.obj: CMakeFiles/BrickBreaker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\BrickBreaker\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BrickBreaker.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BrickBreaker.dir/main.cpp.obj -MF CMakeFiles\BrickBreaker.dir\main.cpp.obj.d -o CMakeFiles\BrickBreaker.dir\main.cpp.obj -c D:\BrickBreaker\main.cpp

CMakeFiles/BrickBreaker.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BrickBreaker.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\BrickBreaker\main.cpp > CMakeFiles\BrickBreaker.dir\main.cpp.i

CMakeFiles/BrickBreaker.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BrickBreaker.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\BrickBreaker\main.cpp -o CMakeFiles\BrickBreaker.dir\main.cpp.s

CMakeFiles/BrickBreaker.dir/menu.cpp.obj: CMakeFiles/BrickBreaker.dir/flags.make
CMakeFiles/BrickBreaker.dir/menu.cpp.obj: CMakeFiles/BrickBreaker.dir/includes_CXX.rsp
CMakeFiles/BrickBreaker.dir/menu.cpp.obj: ../menu.cpp
CMakeFiles/BrickBreaker.dir/menu.cpp.obj: CMakeFiles/BrickBreaker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\BrickBreaker\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BrickBreaker.dir/menu.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BrickBreaker.dir/menu.cpp.obj -MF CMakeFiles\BrickBreaker.dir\menu.cpp.obj.d -o CMakeFiles\BrickBreaker.dir\menu.cpp.obj -c D:\BrickBreaker\menu.cpp

CMakeFiles/BrickBreaker.dir/menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BrickBreaker.dir/menu.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\BrickBreaker\menu.cpp > CMakeFiles\BrickBreaker.dir\menu.cpp.i

CMakeFiles/BrickBreaker.dir/menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BrickBreaker.dir/menu.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\BrickBreaker\menu.cpp -o CMakeFiles\BrickBreaker.dir\menu.cpp.s

# Object files for target BrickBreaker
BrickBreaker_OBJECTS = \
"CMakeFiles/BrickBreaker.dir/main.cpp.obj" \
"CMakeFiles/BrickBreaker.dir/menu.cpp.obj"

# External object files for target BrickBreaker
BrickBreaker_EXTERNAL_OBJECTS =

BrickBreaker.exe: CMakeFiles/BrickBreaker.dir/main.cpp.obj
BrickBreaker.exe: CMakeFiles/BrickBreaker.dir/menu.cpp.obj
BrickBreaker.exe: CMakeFiles/BrickBreaker.dir/build.make
BrickBreaker.exe: C:/mingw64/lib/libsfml-system-s-d.a
BrickBreaker.exe: C:/mingw64/lib/libsfml-window-s-d.a
BrickBreaker.exe: C:/mingw64/lib/libsfml-graphics-s-d.a
BrickBreaker.exe: C:/mingw64/lib/libsfml-window-s-d.a
BrickBreaker.exe: C:/mingw64/lib/libsfml-system-s-d.a
BrickBreaker.exe: C:/mingw64/lib/libfreetype.a
BrickBreaker.exe: CMakeFiles/BrickBreaker.dir/linklibs.rsp
BrickBreaker.exe: CMakeFiles/BrickBreaker.dir/objects1.rsp
BrickBreaker.exe: CMakeFiles/BrickBreaker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\BrickBreaker\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable BrickBreaker.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BrickBreaker.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BrickBreaker.dir/build: BrickBreaker.exe
.PHONY : CMakeFiles/BrickBreaker.dir/build

CMakeFiles/BrickBreaker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BrickBreaker.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BrickBreaker.dir/clean

CMakeFiles/BrickBreaker.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\BrickBreaker D:\BrickBreaker D:\BrickBreaker\cmake-build-debug D:\BrickBreaker\cmake-build-debug D:\BrickBreaker\cmake-build-debug\CMakeFiles\BrickBreaker.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BrickBreaker.dir/depend

