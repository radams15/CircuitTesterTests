# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/files/scripts/CircuitTesterTests/DiagramEditor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/files/scripts/CircuitTesterTests/DiagramEditor/build

# Utility rule file for DiagramEditor_autogen.

# Include the progress variables for this target.
include CMakeFiles/DiagramEditor_autogen.dir/progress.make

CMakeFiles/DiagramEditor_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/files/scripts/CircuitTesterTests/DiagramEditor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target DiagramEditor"
	/usr/bin/cmake -E cmake_autogen /mnt/files/scripts/CircuitTesterTests/DiagramEditor/build/CMakeFiles/DiagramEditor_autogen.dir/AutogenInfo.json ""

DiagramEditor_autogen: CMakeFiles/DiagramEditor_autogen
DiagramEditor_autogen: CMakeFiles/DiagramEditor_autogen.dir/build.make

.PHONY : DiagramEditor_autogen

# Rule to build all files generated by this target.
CMakeFiles/DiagramEditor_autogen.dir/build: DiagramEditor_autogen

.PHONY : CMakeFiles/DiagramEditor_autogen.dir/build

CMakeFiles/DiagramEditor_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DiagramEditor_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DiagramEditor_autogen.dir/clean

CMakeFiles/DiagramEditor_autogen.dir/depend:
	cd /mnt/files/scripts/CircuitTesterTests/DiagramEditor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/files/scripts/CircuitTesterTests/DiagramEditor /mnt/files/scripts/CircuitTesterTests/DiagramEditor /mnt/files/scripts/CircuitTesterTests/DiagramEditor/build /mnt/files/scripts/CircuitTesterTests/DiagramEditor/build /mnt/files/scripts/CircuitTesterTests/DiagramEditor/build/CMakeFiles/DiagramEditor_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DiagramEditor_autogen.dir/depend
