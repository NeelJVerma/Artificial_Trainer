# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /snap/clion/58/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/58/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Artificial_Trainer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Artificial_Trainer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Artificial_Trainer.dir/flags.make

CMakeFiles/Artificial_Trainer.dir/src/main.cc.o: CMakeFiles/Artificial_Trainer.dir/flags.make
CMakeFiles/Artificial_Trainer.dir/src/main.cc.o: ../src/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Artificial_Trainer.dir/src/main.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Artificial_Trainer.dir/src/main.cc.o -c /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/main.cc

CMakeFiles/Artificial_Trainer.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Artificial_Trainer.dir/src/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/main.cc > CMakeFiles/Artificial_Trainer.dir/src/main.cc.i

CMakeFiles/Artificial_Trainer.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Artificial_Trainer.dir/src/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/main.cc -o CMakeFiles/Artificial_Trainer.dir/src/main.cc.s

CMakeFiles/Artificial_Trainer.dir/src/clientelements/gui.cc.o: CMakeFiles/Artificial_Trainer.dir/flags.make
CMakeFiles/Artificial_Trainer.dir/src/clientelements/gui.cc.o: ../src/clientelements/gui.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Artificial_Trainer.dir/src/clientelements/gui.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Artificial_Trainer.dir/src/clientelements/gui.cc.o -c /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/clientelements/gui.cc

CMakeFiles/Artificial_Trainer.dir/src/clientelements/gui.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Artificial_Trainer.dir/src/clientelements/gui.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/clientelements/gui.cc > CMakeFiles/Artificial_Trainer.dir/src/clientelements/gui.cc.i

CMakeFiles/Artificial_Trainer.dir/src/clientelements/gui.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Artificial_Trainer.dir/src/clientelements/gui.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/clientelements/gui.cc -o CMakeFiles/Artificial_Trainer.dir/src/clientelements/gui.cc.s

CMakeFiles/Artificial_Trainer.dir/src/pokemon/pokemon.cc.o: CMakeFiles/Artificial_Trainer.dir/flags.make
CMakeFiles/Artificial_Trainer.dir/src/pokemon/pokemon.cc.o: ../src/pokemon/pokemon.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Artificial_Trainer.dir/src/pokemon/pokemon.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Artificial_Trainer.dir/src/pokemon/pokemon.cc.o -c /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/pokemon/pokemon.cc

CMakeFiles/Artificial_Trainer.dir/src/pokemon/pokemon.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Artificial_Trainer.dir/src/pokemon/pokemon.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/pokemon/pokemon.cc > CMakeFiles/Artificial_Trainer.dir/src/pokemon/pokemon.cc.i

CMakeFiles/Artificial_Trainer.dir/src/pokemon/pokemon.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Artificial_Trainer.dir/src/pokemon/pokemon.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/pokemon/pokemon.cc -o CMakeFiles/Artificial_Trainer.dir/src/pokemon/pokemon.cc.s

CMakeFiles/Artificial_Trainer.dir/src/clientelements/sanitizer.cc.o: CMakeFiles/Artificial_Trainer.dir/flags.make
CMakeFiles/Artificial_Trainer.dir/src/clientelements/sanitizer.cc.o: ../src/clientelements/sanitizer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Artificial_Trainer.dir/src/clientelements/sanitizer.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Artificial_Trainer.dir/src/clientelements/sanitizer.cc.o -c /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/clientelements/sanitizer.cc

CMakeFiles/Artificial_Trainer.dir/src/clientelements/sanitizer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Artificial_Trainer.dir/src/clientelements/sanitizer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/clientelements/sanitizer.cc > CMakeFiles/Artificial_Trainer.dir/src/clientelements/sanitizer.cc.i

CMakeFiles/Artificial_Trainer.dir/src/clientelements/sanitizer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Artificial_Trainer.dir/src/clientelements/sanitizer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/clientelements/sanitizer.cc -o CMakeFiles/Artificial_Trainer.dir/src/clientelements/sanitizer.cc.s

CMakeFiles/Artificial_Trainer.dir/src/team/team.cc.o: CMakeFiles/Artificial_Trainer.dir/flags.make
CMakeFiles/Artificial_Trainer.dir/src/team/team.cc.o: ../src/team/team.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Artificial_Trainer.dir/src/team/team.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Artificial_Trainer.dir/src/team/team.cc.o -c /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/team/team.cc

CMakeFiles/Artificial_Trainer.dir/src/team/team.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Artificial_Trainer.dir/src/team/team.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/team/team.cc > CMakeFiles/Artificial_Trainer.dir/src/team/team.cc.i

CMakeFiles/Artificial_Trainer.dir/src/team/team.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Artificial_Trainer.dir/src/team/team.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/team/team.cc -o CMakeFiles/Artificial_Trainer.dir/src/team/team.cc.s

CMakeFiles/Artificial_Trainer.dir/src/stat/stat.cc.o: CMakeFiles/Artificial_Trainer.dir/flags.make
CMakeFiles/Artificial_Trainer.dir/src/stat/stat.cc.o: ../src/stat/stat.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Artificial_Trainer.dir/src/stat/stat.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Artificial_Trainer.dir/src/stat/stat.cc.o -c /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/stat/stat.cc

CMakeFiles/Artificial_Trainer.dir/src/stat/stat.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Artificial_Trainer.dir/src/stat/stat.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/stat/stat.cc > CMakeFiles/Artificial_Trainer.dir/src/stat/stat.cc.i

CMakeFiles/Artificial_Trainer.dir/src/stat/stat.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Artificial_Trainer.dir/src/stat/stat.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/stat/stat.cc -o CMakeFiles/Artificial_Trainer.dir/src/stat/stat.cc.s

CMakeFiles/Artificial_Trainer.dir/src/stat/hp.cc.o: CMakeFiles/Artificial_Trainer.dir/flags.make
CMakeFiles/Artificial_Trainer.dir/src/stat/hp.cc.o: ../src/stat/hp.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Artificial_Trainer.dir/src/stat/hp.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Artificial_Trainer.dir/src/stat/hp.cc.o -c /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/stat/hp.cc

CMakeFiles/Artificial_Trainer.dir/src/stat/hp.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Artificial_Trainer.dir/src/stat/hp.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/stat/hp.cc > CMakeFiles/Artificial_Trainer.dir/src/stat/hp.cc.i

CMakeFiles/Artificial_Trainer.dir/src/stat/hp.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Artificial_Trainer.dir/src/stat/hp.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/stat/hp.cc -o CMakeFiles/Artificial_Trainer.dir/src/stat/hp.cc.s

CMakeFiles/Artificial_Trainer.dir/src/stat/ev.cc.o: CMakeFiles/Artificial_Trainer.dir/flags.make
CMakeFiles/Artificial_Trainer.dir/src/stat/ev.cc.o: ../src/stat/ev.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Artificial_Trainer.dir/src/stat/ev.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Artificial_Trainer.dir/src/stat/ev.cc.o -c /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/stat/ev.cc

CMakeFiles/Artificial_Trainer.dir/src/stat/ev.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Artificial_Trainer.dir/src/stat/ev.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/stat/ev.cc > CMakeFiles/Artificial_Trainer.dir/src/stat/ev.cc.i

CMakeFiles/Artificial_Trainer.dir/src/stat/ev.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Artificial_Trainer.dir/src/stat/ev.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/stat/ev.cc -o CMakeFiles/Artificial_Trainer.dir/src/stat/ev.cc.s

CMakeFiles/Artificial_Trainer.dir/src/stat/iv.cc.o: CMakeFiles/Artificial_Trainer.dir/flags.make
CMakeFiles/Artificial_Trainer.dir/src/stat/iv.cc.o: ../src/stat/iv.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Artificial_Trainer.dir/src/stat/iv.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Artificial_Trainer.dir/src/stat/iv.cc.o -c /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/stat/iv.cc

CMakeFiles/Artificial_Trainer.dir/src/stat/iv.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Artificial_Trainer.dir/src/stat/iv.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/stat/iv.cc > CMakeFiles/Artificial_Trainer.dir/src/stat/iv.cc.i

CMakeFiles/Artificial_Trainer.dir/src/stat/iv.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Artificial_Trainer.dir/src/stat/iv.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/stat/iv.cc -o CMakeFiles/Artificial_Trainer.dir/src/stat/iv.cc.s

CMakeFiles/Artificial_Trainer.dir/src/stat/statscontainer.cc.o: CMakeFiles/Artificial_Trainer.dir/flags.make
CMakeFiles/Artificial_Trainer.dir/src/stat/statscontainer.cc.o: ../src/stat/statscontainer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Artificial_Trainer.dir/src/stat/statscontainer.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Artificial_Trainer.dir/src/stat/statscontainer.cc.o -c /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/stat/statscontainer.cc

CMakeFiles/Artificial_Trainer.dir/src/stat/statscontainer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Artificial_Trainer.dir/src/stat/statscontainer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/stat/statscontainer.cc > CMakeFiles/Artificial_Trainer.dir/src/stat/statscontainer.cc.i

CMakeFiles/Artificial_Trainer.dir/src/stat/statscontainer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Artificial_Trainer.dir/src/stat/statscontainer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/stat/statscontainer.cc -o CMakeFiles/Artificial_Trainer.dir/src/stat/statscontainer.cc.s

CMakeFiles/Artificial_Trainer.dir/src/battle/battle.cc.o: CMakeFiles/Artificial_Trainer.dir/flags.make
CMakeFiles/Artificial_Trainer.dir/src/battle/battle.cc.o: ../src/battle/battle.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Artificial_Trainer.dir/src/battle/battle.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Artificial_Trainer.dir/src/battle/battle.cc.o -c /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/battle/battle.cc

CMakeFiles/Artificial_Trainer.dir/src/battle/battle.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Artificial_Trainer.dir/src/battle/battle.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/battle/battle.cc > CMakeFiles/Artificial_Trainer.dir/src/battle/battle.cc.i

CMakeFiles/Artificial_Trainer.dir/src/battle/battle.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Artificial_Trainer.dir/src/battle/battle.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/battle/battle.cc -o CMakeFiles/Artificial_Trainer.dir/src/battle/battle.cc.s

CMakeFiles/Artificial_Trainer.dir/src/stringconversions/stringconverter.cc.o: CMakeFiles/Artificial_Trainer.dir/flags.make
CMakeFiles/Artificial_Trainer.dir/src/stringconversions/stringconverter.cc.o: ../src/stringconversions/stringconverter.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Artificial_Trainer.dir/src/stringconversions/stringconverter.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Artificial_Trainer.dir/src/stringconversions/stringconverter.cc.o -c /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/stringconversions/stringconverter.cc

CMakeFiles/Artificial_Trainer.dir/src/stringconversions/stringconverter.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Artificial_Trainer.dir/src/stringconversions/stringconverter.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/stringconversions/stringconverter.cc > CMakeFiles/Artificial_Trainer.dir/src/stringconversions/stringconverter.cc.i

CMakeFiles/Artificial_Trainer.dir/src/stringconversions/stringconverter.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Artificial_Trainer.dir/src/stringconversions/stringconverter.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/stringconversions/stringconverter.cc -o CMakeFiles/Artificial_Trainer.dir/src/stringconversions/stringconverter.cc.s

CMakeFiles/Artificial_Trainer.dir/src/clientelements/inputhandler.cc.o: CMakeFiles/Artificial_Trainer.dir/flags.make
CMakeFiles/Artificial_Trainer.dir/src/clientelements/inputhandler.cc.o: ../src/clientelements/inputhandler.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Artificial_Trainer.dir/src/clientelements/inputhandler.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Artificial_Trainer.dir/src/clientelements/inputhandler.cc.o -c /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/clientelements/inputhandler.cc

CMakeFiles/Artificial_Trainer.dir/src/clientelements/inputhandler.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Artificial_Trainer.dir/src/clientelements/inputhandler.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/clientelements/inputhandler.cc > CMakeFiles/Artificial_Trainer.dir/src/clientelements/inputhandler.cc.i

CMakeFiles/Artificial_Trainer.dir/src/clientelements/inputhandler.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Artificial_Trainer.dir/src/clientelements/inputhandler.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/src/clientelements/inputhandler.cc -o CMakeFiles/Artificial_Trainer.dir/src/clientelements/inputhandler.cc.s

# Object files for target Artificial_Trainer
Artificial_Trainer_OBJECTS = \
"CMakeFiles/Artificial_Trainer.dir/src/main.cc.o" \
"CMakeFiles/Artificial_Trainer.dir/src/clientelements/gui.cc.o" \
"CMakeFiles/Artificial_Trainer.dir/src/pokemon/pokemon.cc.o" \
"CMakeFiles/Artificial_Trainer.dir/src/clientelements/sanitizer.cc.o" \
"CMakeFiles/Artificial_Trainer.dir/src/team/team.cc.o" \
"CMakeFiles/Artificial_Trainer.dir/src/stat/stat.cc.o" \
"CMakeFiles/Artificial_Trainer.dir/src/stat/hp.cc.o" \
"CMakeFiles/Artificial_Trainer.dir/src/stat/ev.cc.o" \
"CMakeFiles/Artificial_Trainer.dir/src/stat/iv.cc.o" \
"CMakeFiles/Artificial_Trainer.dir/src/stat/statscontainer.cc.o" \
"CMakeFiles/Artificial_Trainer.dir/src/battle/battle.cc.o" \
"CMakeFiles/Artificial_Trainer.dir/src/stringconversions/stringconverter.cc.o" \
"CMakeFiles/Artificial_Trainer.dir/src/clientelements/inputhandler.cc.o"

# External object files for target Artificial_Trainer
Artificial_Trainer_EXTERNAL_OBJECTS =

Artificial_Trainer: CMakeFiles/Artificial_Trainer.dir/src/main.cc.o
Artificial_Trainer: CMakeFiles/Artificial_Trainer.dir/src/clientelements/gui.cc.o
Artificial_Trainer: CMakeFiles/Artificial_Trainer.dir/src/pokemon/pokemon.cc.o
Artificial_Trainer: CMakeFiles/Artificial_Trainer.dir/src/clientelements/sanitizer.cc.o
Artificial_Trainer: CMakeFiles/Artificial_Trainer.dir/src/team/team.cc.o
Artificial_Trainer: CMakeFiles/Artificial_Trainer.dir/src/stat/stat.cc.o
Artificial_Trainer: CMakeFiles/Artificial_Trainer.dir/src/stat/hp.cc.o
Artificial_Trainer: CMakeFiles/Artificial_Trainer.dir/src/stat/ev.cc.o
Artificial_Trainer: CMakeFiles/Artificial_Trainer.dir/src/stat/iv.cc.o
Artificial_Trainer: CMakeFiles/Artificial_Trainer.dir/src/stat/statscontainer.cc.o
Artificial_Trainer: CMakeFiles/Artificial_Trainer.dir/src/battle/battle.cc.o
Artificial_Trainer: CMakeFiles/Artificial_Trainer.dir/src/stringconversions/stringconverter.cc.o
Artificial_Trainer: CMakeFiles/Artificial_Trainer.dir/src/clientelements/inputhandler.cc.o
Artificial_Trainer: CMakeFiles/Artificial_Trainer.dir/build.make
Artificial_Trainer: CMakeFiles/Artificial_Trainer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX executable Artificial_Trainer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Artificial_Trainer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Artificial_Trainer.dir/build: Artificial_Trainer

.PHONY : CMakeFiles/Artificial_Trainer.dir/build

CMakeFiles/Artificial_Trainer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Artificial_Trainer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Artificial_Trainer.dir/clean

CMakeFiles/Artificial_Trainer.dir/depend:
	cd /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/cmake-build-debug /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/cmake-build-debug /home/neel/Desktop/Ramapo_Computer_Science/Ramapo_Senior_Year/Second_Semester/Senior_Project/Artificial_Trainer/cmake-build-debug/CMakeFiles/Artificial_Trainer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Artificial_Trainer.dir/depend

