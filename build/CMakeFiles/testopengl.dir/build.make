# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/phvera/projects/testopengl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/phvera/projects/testopengl/build

# Include any dependencies generated for this target.
include CMakeFiles/testopengl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testopengl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testopengl.dir/flags.make

CMakeFiles/testopengl.dir/brol.o: CMakeFiles/testopengl.dir/flags.make
CMakeFiles/testopengl.dir/brol.o: ../brol.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/phvera/projects/testopengl/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/testopengl.dir/brol.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testopengl.dir/brol.o -c /home/phvera/projects/testopengl/brol.cpp

CMakeFiles/testopengl.dir/brol.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testopengl.dir/brol.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/phvera/projects/testopengl/brol.cpp > CMakeFiles/testopengl.dir/brol.i

CMakeFiles/testopengl.dir/brol.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testopengl.dir/brol.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/phvera/projects/testopengl/brol.cpp -o CMakeFiles/testopengl.dir/brol.s

CMakeFiles/testopengl.dir/brol.o.requires:
.PHONY : CMakeFiles/testopengl.dir/brol.o.requires

CMakeFiles/testopengl.dir/brol.o.provides: CMakeFiles/testopengl.dir/brol.o.requires
	$(MAKE) -f CMakeFiles/testopengl.dir/build.make CMakeFiles/testopengl.dir/brol.o.provides.build
.PHONY : CMakeFiles/testopengl.dir/brol.o.provides

CMakeFiles/testopengl.dir/brol.o.provides.build: CMakeFiles/testopengl.dir/brol.o

CMakeFiles/testopengl.dir/sdlglutils.o: CMakeFiles/testopengl.dir/flags.make
CMakeFiles/testopengl.dir/sdlglutils.o: ../sdlglutils.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/phvera/projects/testopengl/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/testopengl.dir/sdlglutils.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testopengl.dir/sdlglutils.o -c /home/phvera/projects/testopengl/sdlglutils.cpp

CMakeFiles/testopengl.dir/sdlglutils.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testopengl.dir/sdlglutils.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/phvera/projects/testopengl/sdlglutils.cpp > CMakeFiles/testopengl.dir/sdlglutils.i

CMakeFiles/testopengl.dir/sdlglutils.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testopengl.dir/sdlglutils.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/phvera/projects/testopengl/sdlglutils.cpp -o CMakeFiles/testopengl.dir/sdlglutils.s

CMakeFiles/testopengl.dir/sdlglutils.o.requires:
.PHONY : CMakeFiles/testopengl.dir/sdlglutils.o.requires

CMakeFiles/testopengl.dir/sdlglutils.o.provides: CMakeFiles/testopengl.dir/sdlglutils.o.requires
	$(MAKE) -f CMakeFiles/testopengl.dir/build.make CMakeFiles/testopengl.dir/sdlglutils.o.provides.build
.PHONY : CMakeFiles/testopengl.dir/sdlglutils.o.provides

CMakeFiles/testopengl.dir/sdlglutils.o.provides.build: CMakeFiles/testopengl.dir/sdlglutils.o

CMakeFiles/testopengl.dir/TrackBallCamera.o: CMakeFiles/testopengl.dir/flags.make
CMakeFiles/testopengl.dir/TrackBallCamera.o: ../TrackBallCamera.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/phvera/projects/testopengl/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/testopengl.dir/TrackBallCamera.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testopengl.dir/TrackBallCamera.o -c /home/phvera/projects/testopengl/TrackBallCamera.cpp

CMakeFiles/testopengl.dir/TrackBallCamera.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testopengl.dir/TrackBallCamera.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/phvera/projects/testopengl/TrackBallCamera.cpp > CMakeFiles/testopengl.dir/TrackBallCamera.i

CMakeFiles/testopengl.dir/TrackBallCamera.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testopengl.dir/TrackBallCamera.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/phvera/projects/testopengl/TrackBallCamera.cpp -o CMakeFiles/testopengl.dir/TrackBallCamera.s

CMakeFiles/testopengl.dir/TrackBallCamera.o.requires:
.PHONY : CMakeFiles/testopengl.dir/TrackBallCamera.o.requires

CMakeFiles/testopengl.dir/TrackBallCamera.o.provides: CMakeFiles/testopengl.dir/TrackBallCamera.o.requires
	$(MAKE) -f CMakeFiles/testopengl.dir/build.make CMakeFiles/testopengl.dir/TrackBallCamera.o.provides.build
.PHONY : CMakeFiles/testopengl.dir/TrackBallCamera.o.provides

CMakeFiles/testopengl.dir/TrackBallCamera.o.provides.build: CMakeFiles/testopengl.dir/TrackBallCamera.o

# Object files for target testopengl
testopengl_OBJECTS = \
"CMakeFiles/testopengl.dir/brol.o" \
"CMakeFiles/testopengl.dir/sdlglutils.o" \
"CMakeFiles/testopengl.dir/TrackBallCamera.o"

# External object files for target testopengl
testopengl_EXTERNAL_OBJECTS =

testopengl: CMakeFiles/testopengl.dir/brol.o
testopengl: CMakeFiles/testopengl.dir/sdlglutils.o
testopengl: CMakeFiles/testopengl.dir/TrackBallCamera.o
testopengl: CMakeFiles/testopengl.dir/build.make
testopengl: CMakeFiles/testopengl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable testopengl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testopengl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testopengl.dir/build: testopengl
.PHONY : CMakeFiles/testopengl.dir/build

CMakeFiles/testopengl.dir/requires: CMakeFiles/testopengl.dir/brol.o.requires
CMakeFiles/testopengl.dir/requires: CMakeFiles/testopengl.dir/sdlglutils.o.requires
CMakeFiles/testopengl.dir/requires: CMakeFiles/testopengl.dir/TrackBallCamera.o.requires
.PHONY : CMakeFiles/testopengl.dir/requires

CMakeFiles/testopengl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testopengl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testopengl.dir/clean

CMakeFiles/testopengl.dir/depend:
	cd /home/phvera/projects/testopengl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/phvera/projects/testopengl /home/phvera/projects/testopengl /home/phvera/projects/testopengl/build /home/phvera/projects/testopengl/build /home/phvera/projects/testopengl/build/CMakeFiles/testopengl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testopengl.dir/depend

