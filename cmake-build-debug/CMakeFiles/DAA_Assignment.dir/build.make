# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Dev\DAA_Assignment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Dev\DAA_Assignment\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DAA_Assignment.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DAA_Assignment.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DAA_Assignment.dir/flags.make

CMakeFiles/DAA_Assignment.dir/main.cpp.obj: CMakeFiles/DAA_Assignment.dir/flags.make
CMakeFiles/DAA_Assignment.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\DAA_Assignment\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DAA_Assignment.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DAA_Assignment.dir\main.cpp.obj -c D:\Dev\DAA_Assignment\main.cpp

CMakeFiles/DAA_Assignment.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DAA_Assignment.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\DAA_Assignment\main.cpp > CMakeFiles\DAA_Assignment.dir\main.cpp.i

CMakeFiles/DAA_Assignment.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DAA_Assignment.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Dev\DAA_Assignment\main.cpp -o CMakeFiles\DAA_Assignment.dir\main.cpp.s

CMakeFiles/DAA_Assignment.dir/src/Point.cpp.obj: CMakeFiles/DAA_Assignment.dir/flags.make
CMakeFiles/DAA_Assignment.dir/src/Point.cpp.obj: ../src/Point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\DAA_Assignment\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DAA_Assignment.dir/src/Point.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DAA_Assignment.dir\src\Point.cpp.obj -c D:\Dev\DAA_Assignment\src\Point.cpp

CMakeFiles/DAA_Assignment.dir/src/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DAA_Assignment.dir/src/Point.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\DAA_Assignment\src\Point.cpp > CMakeFiles\DAA_Assignment.dir\src\Point.cpp.i

CMakeFiles/DAA_Assignment.dir/src/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DAA_Assignment.dir/src/Point.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Dev\DAA_Assignment\src\Point.cpp -o CMakeFiles\DAA_Assignment.dir\src\Point.cpp.s

CMakeFiles/DAA_Assignment.dir/src/Interval.cpp.obj: CMakeFiles/DAA_Assignment.dir/flags.make
CMakeFiles/DAA_Assignment.dir/src/Interval.cpp.obj: ../src/Interval.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\DAA_Assignment\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DAA_Assignment.dir/src/Interval.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DAA_Assignment.dir\src\Interval.cpp.obj -c D:\Dev\DAA_Assignment\src\Interval.cpp

CMakeFiles/DAA_Assignment.dir/src/Interval.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DAA_Assignment.dir/src/Interval.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\DAA_Assignment\src\Interval.cpp > CMakeFiles\DAA_Assignment.dir\src\Interval.cpp.i

CMakeFiles/DAA_Assignment.dir/src/Interval.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DAA_Assignment.dir/src/Interval.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Dev\DAA_Assignment\src\Interval.cpp -o CMakeFiles\DAA_Assignment.dir\src\Interval.cpp.s

CMakeFiles/DAA_Assignment.dir/src/Rectangle.cpp.obj: CMakeFiles/DAA_Assignment.dir/flags.make
CMakeFiles/DAA_Assignment.dir/src/Rectangle.cpp.obj: ../src/Rectangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\DAA_Assignment\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DAA_Assignment.dir/src/Rectangle.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DAA_Assignment.dir\src\Rectangle.cpp.obj -c D:\Dev\DAA_Assignment\src\Rectangle.cpp

CMakeFiles/DAA_Assignment.dir/src/Rectangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DAA_Assignment.dir/src/Rectangle.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\DAA_Assignment\src\Rectangle.cpp > CMakeFiles\DAA_Assignment.dir\src\Rectangle.cpp.i

CMakeFiles/DAA_Assignment.dir/src/Rectangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DAA_Assignment.dir/src/Rectangle.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Dev\DAA_Assignment\src\Rectangle.cpp -o CMakeFiles\DAA_Assignment.dir\src\Rectangle.cpp.s

CMakeFiles/DAA_Assignment.dir/src/Stripe.cpp.obj: CMakeFiles/DAA_Assignment.dir/flags.make
CMakeFiles/DAA_Assignment.dir/src/Stripe.cpp.obj: ../src/Stripe.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\DAA_Assignment\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/DAA_Assignment.dir/src/Stripe.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DAA_Assignment.dir\src\Stripe.cpp.obj -c D:\Dev\DAA_Assignment\src\Stripe.cpp

CMakeFiles/DAA_Assignment.dir/src/Stripe.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DAA_Assignment.dir/src/Stripe.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\DAA_Assignment\src\Stripe.cpp > CMakeFiles\DAA_Assignment.dir\src\Stripe.cpp.i

CMakeFiles/DAA_Assignment.dir/src/Stripe.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DAA_Assignment.dir/src/Stripe.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Dev\DAA_Assignment\src\Stripe.cpp -o CMakeFiles\DAA_Assignment.dir\src\Stripe.cpp.s

CMakeFiles/DAA_Assignment.dir/src/MeasureHelper.cpp.obj: CMakeFiles/DAA_Assignment.dir/flags.make
CMakeFiles/DAA_Assignment.dir/src/MeasureHelper.cpp.obj: ../src/MeasureHelper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\DAA_Assignment\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/DAA_Assignment.dir/src/MeasureHelper.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DAA_Assignment.dir\src\MeasureHelper.cpp.obj -c D:\Dev\DAA_Assignment\src\MeasureHelper.cpp

CMakeFiles/DAA_Assignment.dir/src/MeasureHelper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DAA_Assignment.dir/src/MeasureHelper.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\DAA_Assignment\src\MeasureHelper.cpp > CMakeFiles\DAA_Assignment.dir\src\MeasureHelper.cpp.i

CMakeFiles/DAA_Assignment.dir/src/MeasureHelper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DAA_Assignment.dir/src/MeasureHelper.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Dev\DAA_Assignment\src\MeasureHelper.cpp -o CMakeFiles\DAA_Assignment.dir\src\MeasureHelper.cpp.s

CMakeFiles/DAA_Assignment.dir/src/Edge.cpp.obj: CMakeFiles/DAA_Assignment.dir/flags.make
CMakeFiles/DAA_Assignment.dir/src/Edge.cpp.obj: ../src/Edge.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\DAA_Assignment\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/DAA_Assignment.dir/src/Edge.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DAA_Assignment.dir\src\Edge.cpp.obj -c D:\Dev\DAA_Assignment\src\Edge.cpp

CMakeFiles/DAA_Assignment.dir/src/Edge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DAA_Assignment.dir/src/Edge.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\DAA_Assignment\src\Edge.cpp > CMakeFiles\DAA_Assignment.dir\src\Edge.cpp.i

CMakeFiles/DAA_Assignment.dir/src/Edge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DAA_Assignment.dir/src/Edge.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Dev\DAA_Assignment\src\Edge.cpp -o CMakeFiles\DAA_Assignment.dir\src\Edge.cpp.s

CMakeFiles/DAA_Assignment.dir/src/IntervalHelper.cpp.obj: CMakeFiles/DAA_Assignment.dir/flags.make
CMakeFiles/DAA_Assignment.dir/src/IntervalHelper.cpp.obj: ../src/IntervalHelper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\DAA_Assignment\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/DAA_Assignment.dir/src/IntervalHelper.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DAA_Assignment.dir\src\IntervalHelper.cpp.obj -c D:\Dev\DAA_Assignment\src\IntervalHelper.cpp

CMakeFiles/DAA_Assignment.dir/src/IntervalHelper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DAA_Assignment.dir/src/IntervalHelper.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\DAA_Assignment\src\IntervalHelper.cpp > CMakeFiles\DAA_Assignment.dir\src\IntervalHelper.cpp.i

CMakeFiles/DAA_Assignment.dir/src/IntervalHelper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DAA_Assignment.dir/src/IntervalHelper.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Dev\DAA_Assignment\src\IntervalHelper.cpp -o CMakeFiles\DAA_Assignment.dir\src\IntervalHelper.cpp.s

CMakeFiles/DAA_Assignment.dir/src/StripeOutput.cpp.obj: CMakeFiles/DAA_Assignment.dir/flags.make
CMakeFiles/DAA_Assignment.dir/src/StripeOutput.cpp.obj: ../src/StripeOutput.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\DAA_Assignment\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/DAA_Assignment.dir/src/StripeOutput.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DAA_Assignment.dir\src\StripeOutput.cpp.obj -c D:\Dev\DAA_Assignment\src\StripeOutput.cpp

CMakeFiles/DAA_Assignment.dir/src/StripeOutput.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DAA_Assignment.dir/src/StripeOutput.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\DAA_Assignment\src\StripeOutput.cpp > CMakeFiles\DAA_Assignment.dir\src\StripeOutput.cpp.i

CMakeFiles/DAA_Assignment.dir/src/StripeOutput.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DAA_Assignment.dir/src/StripeOutput.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Dev\DAA_Assignment\src\StripeOutput.cpp -o CMakeFiles\DAA_Assignment.dir\src\StripeOutput.cpp.s

CMakeFiles/DAA_Assignment.dir/src/Ctree.cpp.obj: CMakeFiles/DAA_Assignment.dir/flags.make
CMakeFiles/DAA_Assignment.dir/src/Ctree.cpp.obj: ../src/Ctree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\DAA_Assignment\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/DAA_Assignment.dir/src/Ctree.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DAA_Assignment.dir\src\Ctree.cpp.obj -c D:\Dev\DAA_Assignment\src\Ctree.cpp

CMakeFiles/DAA_Assignment.dir/src/Ctree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DAA_Assignment.dir/src/Ctree.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\DAA_Assignment\src\Ctree.cpp > CMakeFiles\DAA_Assignment.dir\src\Ctree.cpp.i

CMakeFiles/DAA_Assignment.dir/src/Ctree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DAA_Assignment.dir/src/Ctree.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Dev\DAA_Assignment\src\Ctree.cpp -o CMakeFiles\DAA_Assignment.dir\src\Ctree.cpp.s

# Object files for target DAA_Assignment
DAA_Assignment_OBJECTS = \
"CMakeFiles/DAA_Assignment.dir/main.cpp.obj" \
"CMakeFiles/DAA_Assignment.dir/src/Point.cpp.obj" \
"CMakeFiles/DAA_Assignment.dir/src/Interval.cpp.obj" \
"CMakeFiles/DAA_Assignment.dir/src/Rectangle.cpp.obj" \
"CMakeFiles/DAA_Assignment.dir/src/Stripe.cpp.obj" \
"CMakeFiles/DAA_Assignment.dir/src/MeasureHelper.cpp.obj" \
"CMakeFiles/DAA_Assignment.dir/src/Edge.cpp.obj" \
"CMakeFiles/DAA_Assignment.dir/src/IntervalHelper.cpp.obj" \
"CMakeFiles/DAA_Assignment.dir/src/StripeOutput.cpp.obj" \
"CMakeFiles/DAA_Assignment.dir/src/Ctree.cpp.obj"

# External object files for target DAA_Assignment
DAA_Assignment_EXTERNAL_OBJECTS =

DAA_Assignment.exe: CMakeFiles/DAA_Assignment.dir/main.cpp.obj
DAA_Assignment.exe: CMakeFiles/DAA_Assignment.dir/src/Point.cpp.obj
DAA_Assignment.exe: CMakeFiles/DAA_Assignment.dir/src/Interval.cpp.obj
DAA_Assignment.exe: CMakeFiles/DAA_Assignment.dir/src/Rectangle.cpp.obj
DAA_Assignment.exe: CMakeFiles/DAA_Assignment.dir/src/Stripe.cpp.obj
DAA_Assignment.exe: CMakeFiles/DAA_Assignment.dir/src/MeasureHelper.cpp.obj
DAA_Assignment.exe: CMakeFiles/DAA_Assignment.dir/src/Edge.cpp.obj
DAA_Assignment.exe: CMakeFiles/DAA_Assignment.dir/src/IntervalHelper.cpp.obj
DAA_Assignment.exe: CMakeFiles/DAA_Assignment.dir/src/StripeOutput.cpp.obj
DAA_Assignment.exe: CMakeFiles/DAA_Assignment.dir/src/Ctree.cpp.obj
DAA_Assignment.exe: CMakeFiles/DAA_Assignment.dir/build.make
DAA_Assignment.exe: CMakeFiles/DAA_Assignment.dir/linklibs.rsp
DAA_Assignment.exe: CMakeFiles/DAA_Assignment.dir/objects1.rsp
DAA_Assignment.exe: CMakeFiles/DAA_Assignment.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Dev\DAA_Assignment\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable DAA_Assignment.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DAA_Assignment.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DAA_Assignment.dir/build: DAA_Assignment.exe

.PHONY : CMakeFiles/DAA_Assignment.dir/build

CMakeFiles/DAA_Assignment.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DAA_Assignment.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DAA_Assignment.dir/clean

CMakeFiles/DAA_Assignment.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Dev\DAA_Assignment D:\Dev\DAA_Assignment D:\Dev\DAA_Assignment\cmake-build-debug D:\Dev\DAA_Assignment\cmake-build-debug D:\Dev\DAA_Assignment\cmake-build-debug\CMakeFiles\DAA_Assignment.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DAA_Assignment.dir/depend

