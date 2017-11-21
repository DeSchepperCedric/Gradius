# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Cedric/Documents/CloudStation/School/GP/gradius

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Cedric/Documents/CloudStation/School/GP/gradius

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/Applications/CLion.app/Contents/bin/cmake/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/Applications/CLion.app/Contents/bin/cmake/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/Applications/CLion.app/Contents/bin/cmake/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/Applications/CLion.app/Contents/bin/cmake/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/Applications/CLion.app/Contents/bin/cmake/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/Applications/CLion.app/Contents/bin/cmake/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/Applications/CLion.app/Contents/bin/cmake/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/Applications/CLion.app/Contents/bin/cmake/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/Cedric/Documents/CloudStation/School/GP/gradius/CMakeFiles /Users/Cedric/Documents/CloudStation/School/GP/gradius/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/Cedric/Documents/CloudStation/School/GP/gradius/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Gradius

# Build rule for target.
Gradius: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Gradius
.PHONY : Gradius

# fast build rule for target.
Gradius/fast:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/build
.PHONY : Gradius/fast

src/Controller.o: src/Controller.cpp.o

.PHONY : src/Controller.o

# target to build an object file
src/Controller.cpp.o:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/Controller.cpp.o
.PHONY : src/Controller.cpp.o

src/Controller.i: src/Controller.cpp.i

.PHONY : src/Controller.i

# target to preprocess a source file
src/Controller.cpp.i:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/Controller.cpp.i
.PHONY : src/Controller.cpp.i

src/Controller.s: src/Controller.cpp.s

.PHONY : src/Controller.s

# target to generate assembly for a file
src/Controller.cpp.s:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/Controller.cpp.s
.PHONY : src/Controller.cpp.s

src/Entity.o: src/Entity.cpp.o

.PHONY : src/Entity.o

# target to build an object file
src/Entity.cpp.o:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/Entity.cpp.o
.PHONY : src/Entity.cpp.o

src/Entity.i: src/Entity.cpp.i

.PHONY : src/Entity.i

# target to preprocess a source file
src/Entity.cpp.i:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/Entity.cpp.i
.PHONY : src/Entity.cpp.i

src/Entity.s: src/Entity.cpp.s

.PHONY : src/Entity.s

# target to generate assembly for a file
src/Entity.cpp.s:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/Entity.cpp.s
.PHONY : src/Entity.cpp.s

src/EntityRepresentation.o: src/EntityRepresentation.cpp.o

.PHONY : src/EntityRepresentation.o

# target to build an object file
src/EntityRepresentation.cpp.o:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/EntityRepresentation.cpp.o
.PHONY : src/EntityRepresentation.cpp.o

src/EntityRepresentation.i: src/EntityRepresentation.cpp.i

.PHONY : src/EntityRepresentation.i

# target to preprocess a source file
src/EntityRepresentation.cpp.i:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/EntityRepresentation.cpp.i
.PHONY : src/EntityRepresentation.cpp.i

src/EntityRepresentation.s: src/EntityRepresentation.cpp.s

.PHONY : src/EntityRepresentation.s

# target to generate assembly for a file
src/EntityRepresentation.cpp.s:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/EntityRepresentation.cpp.s
.PHONY : src/EntityRepresentation.cpp.s

src/Game.o: src/Game.cpp.o

.PHONY : src/Game.o

# target to build an object file
src/Game.cpp.o:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/Game.cpp.o
.PHONY : src/Game.cpp.o

src/Game.i: src/Game.cpp.i

.PHONY : src/Game.i

# target to preprocess a source file
src/Game.cpp.i:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/Game.cpp.i
.PHONY : src/Game.cpp.i

src/Game.s: src/Game.cpp.s

.PHONY : src/Game.s

# target to generate assembly for a file
src/Game.cpp.s:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/Game.cpp.s
.PHONY : src/Game.cpp.s

src/Model.o: src/Model.cpp.o

.PHONY : src/Model.o

# target to build an object file
src/Model.cpp.o:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/Model.cpp.o
.PHONY : src/Model.cpp.o

src/Model.i: src/Model.cpp.i

.PHONY : src/Model.i

# target to preprocess a source file
src/Model.cpp.i:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/Model.cpp.i
.PHONY : src/Model.cpp.i

src/Model.s: src/Model.cpp.s

.PHONY : src/Model.s

# target to generate assembly for a file
src/Model.cpp.s:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/Model.cpp.s
.PHONY : src/Model.cpp.s

src/MovingEntity.o: src/MovingEntity.cpp.o

.PHONY : src/MovingEntity.o

# target to build an object file
src/MovingEntity.cpp.o:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/MovingEntity.cpp.o
.PHONY : src/MovingEntity.cpp.o

src/MovingEntity.i: src/MovingEntity.cpp.i

.PHONY : src/MovingEntity.i

# target to preprocess a source file
src/MovingEntity.cpp.i:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/MovingEntity.cpp.i
.PHONY : src/MovingEntity.cpp.i

src/MovingEntity.s: src/MovingEntity.cpp.s

.PHONY : src/MovingEntity.s

# target to generate assembly for a file
src/MovingEntity.cpp.s:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/MovingEntity.cpp.s
.PHONY : src/MovingEntity.cpp.s

src/PlayerShip.o: src/PlayerShip.cpp.o

.PHONY : src/PlayerShip.o

# target to build an object file
src/PlayerShip.cpp.o:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/PlayerShip.cpp.o
.PHONY : src/PlayerShip.cpp.o

src/PlayerShip.i: src/PlayerShip.cpp.i

.PHONY : src/PlayerShip.i

# target to preprocess a source file
src/PlayerShip.cpp.i:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/PlayerShip.cpp.i
.PHONY : src/PlayerShip.cpp.i

src/PlayerShip.s: src/PlayerShip.cpp.s

.PHONY : src/PlayerShip.s

# target to generate assembly for a file
src/PlayerShip.cpp.s:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/PlayerShip.cpp.s
.PHONY : src/PlayerShip.cpp.s

src/StationaryEntity.o: src/StationaryEntity.cpp.o

.PHONY : src/StationaryEntity.o

# target to build an object file
src/StationaryEntity.cpp.o:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/StationaryEntity.cpp.o
.PHONY : src/StationaryEntity.cpp.o

src/StationaryEntity.i: src/StationaryEntity.cpp.i

.PHONY : src/StationaryEntity.i

# target to preprocess a source file
src/StationaryEntity.cpp.i:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/StationaryEntity.cpp.i
.PHONY : src/StationaryEntity.cpp.i

src/StationaryEntity.s: src/StationaryEntity.cpp.s

.PHONY : src/StationaryEntity.s

# target to generate assembly for a file
src/StationaryEntity.cpp.s:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/StationaryEntity.cpp.s
.PHONY : src/StationaryEntity.cpp.s

src/Stopwatch.o: src/Stopwatch.cpp.o

.PHONY : src/Stopwatch.o

# target to build an object file
src/Stopwatch.cpp.o:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/Stopwatch.cpp.o
.PHONY : src/Stopwatch.cpp.o

src/Stopwatch.i: src/Stopwatch.cpp.i

.PHONY : src/Stopwatch.i

# target to preprocess a source file
src/Stopwatch.cpp.i:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/Stopwatch.cpp.i
.PHONY : src/Stopwatch.cpp.i

src/Stopwatch.s: src/Stopwatch.cpp.s

.PHONY : src/Stopwatch.s

# target to generate assembly for a file
src/Stopwatch.cpp.s:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/Stopwatch.cpp.s
.PHONY : src/Stopwatch.cpp.s

src/Transformation.o: src/Transformation.cpp.o

.PHONY : src/Transformation.o

# target to build an object file
src/Transformation.cpp.o:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/Transformation.cpp.o
.PHONY : src/Transformation.cpp.o

src/Transformation.i: src/Transformation.cpp.i

.PHONY : src/Transformation.i

# target to preprocess a source file
src/Transformation.cpp.i:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/Transformation.cpp.i
.PHONY : src/Transformation.cpp.i

src/Transformation.s: src/Transformation.cpp.s

.PHONY : src/Transformation.s

# target to generate assembly for a file
src/Transformation.cpp.s:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/Transformation.cpp.s
.PHONY : src/Transformation.cpp.s

src/View.o: src/View.cpp.o

.PHONY : src/View.o

# target to build an object file
src/View.cpp.o:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/View.cpp.o
.PHONY : src/View.cpp.o

src/View.i: src/View.cpp.i

.PHONY : src/View.i

# target to preprocess a source file
src/View.cpp.i:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/View.cpp.i
.PHONY : src/View.cpp.i

src/View.s: src/View.cpp.s

.PHONY : src/View.s

# target to generate assembly for a file
src/View.cpp.s:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/View.cpp.s
.PHONY : src/View.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/Gradius.dir/build.make CMakeFiles/Gradius.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... install"
	@echo "... Gradius"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... src/Controller.o"
	@echo "... src/Controller.i"
	@echo "... src/Controller.s"
	@echo "... src/Entity.o"
	@echo "... src/Entity.i"
	@echo "... src/Entity.s"
	@echo "... src/EntityRepresentation.o"
	@echo "... src/EntityRepresentation.i"
	@echo "... src/EntityRepresentation.s"
	@echo "... src/Game.o"
	@echo "... src/Game.i"
	@echo "... src/Game.s"
	@echo "... src/Model.o"
	@echo "... src/Model.i"
	@echo "... src/Model.s"
	@echo "... src/MovingEntity.o"
	@echo "... src/MovingEntity.i"
	@echo "... src/MovingEntity.s"
	@echo "... src/PlayerShip.o"
	@echo "... src/PlayerShip.i"
	@echo "... src/PlayerShip.s"
	@echo "... src/StationaryEntity.o"
	@echo "... src/StationaryEntity.i"
	@echo "... src/StationaryEntity.s"
	@echo "... src/Stopwatch.o"
	@echo "... src/Stopwatch.i"
	@echo "... src/Stopwatch.s"
	@echo "... src/Transformation.o"
	@echo "... src/Transformation.i"
	@echo "... src/Transformation.s"
	@echo "... src/View.o"
	@echo "... src/View.i"
	@echo "... src/View.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

