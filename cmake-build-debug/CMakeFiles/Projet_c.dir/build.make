# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = C:\Users\alex\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\alex\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\alex\CLionProjects\projetC_S3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\alex\CLionProjects\projetC_S3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Projet_c.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Projet_c.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Projet_c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Projet_c.dir/flags.make

CMakeFiles/Projet_c.dir/main.c.obj: CMakeFiles/Projet_c.dir/flags.make
CMakeFiles/Projet_c.dir/main.c.obj: C:/Users/alex/CLionProjects/projetC_S3/main.c
CMakeFiles/Projet_c.dir/main.c.obj: CMakeFiles/Projet_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alex\CLionProjects\projetC_S3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Projet_c.dir/main.c.obj"
	C:\Users\alex\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Projet_c.dir/main.c.obj -MF CMakeFiles\Projet_c.dir\main.c.obj.d -o CMakeFiles\Projet_c.dir\main.c.obj -c C:\Users\alex\CLionProjects\projetC_S3\main.c

CMakeFiles/Projet_c.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Projet_c.dir/main.c.i"
	C:\Users\alex\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alex\CLionProjects\projetC_S3\main.c > CMakeFiles\Projet_c.dir\main.c.i

CMakeFiles/Projet_c.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Projet_c.dir/main.c.s"
	C:\Users\alex\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alex\CLionProjects\projetC_S3\main.c -o CMakeFiles\Projet_c.dir\main.c.s

CMakeFiles/Projet_c.dir/cell.c.obj: CMakeFiles/Projet_c.dir/flags.make
CMakeFiles/Projet_c.dir/cell.c.obj: C:/Users/alex/CLionProjects/projetC_S3/cell.c
CMakeFiles/Projet_c.dir/cell.c.obj: CMakeFiles/Projet_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alex\CLionProjects\projetC_S3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Projet_c.dir/cell.c.obj"
	C:\Users\alex\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Projet_c.dir/cell.c.obj -MF CMakeFiles\Projet_c.dir\cell.c.obj.d -o CMakeFiles\Projet_c.dir\cell.c.obj -c C:\Users\alex\CLionProjects\projetC_S3\cell.c

CMakeFiles/Projet_c.dir/cell.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Projet_c.dir/cell.c.i"
	C:\Users\alex\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alex\CLionProjects\projetC_S3\cell.c > CMakeFiles\Projet_c.dir\cell.c.i

CMakeFiles/Projet_c.dir/cell.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Projet_c.dir/cell.c.s"
	C:\Users\alex\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alex\CLionProjects\projetC_S3\cell.c -o CMakeFiles\Projet_c.dir\cell.c.s

CMakeFiles/Projet_c.dir/list.c.obj: CMakeFiles/Projet_c.dir/flags.make
CMakeFiles/Projet_c.dir/list.c.obj: C:/Users/alex/CLionProjects/projetC_S3/list.c
CMakeFiles/Projet_c.dir/list.c.obj: CMakeFiles/Projet_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alex\CLionProjects\projetC_S3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Projet_c.dir/list.c.obj"
	C:\Users\alex\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Projet_c.dir/list.c.obj -MF CMakeFiles\Projet_c.dir\list.c.obj.d -o CMakeFiles\Projet_c.dir\list.c.obj -c C:\Users\alex\CLionProjects\projetC_S3\list.c

CMakeFiles/Projet_c.dir/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Projet_c.dir/list.c.i"
	C:\Users\alex\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alex\CLionProjects\projetC_S3\list.c > CMakeFiles\Projet_c.dir\list.c.i

CMakeFiles/Projet_c.dir/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Projet_c.dir/list.c.s"
	C:\Users\alex\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alex\CLionProjects\projetC_S3\list.c -o CMakeFiles\Projet_c.dir\list.c.s

CMakeFiles/Projet_c.dir/timer.c.obj: CMakeFiles/Projet_c.dir/flags.make
CMakeFiles/Projet_c.dir/timer.c.obj: C:/Users/alex/CLionProjects/projetC_S3/timer.c
CMakeFiles/Projet_c.dir/timer.c.obj: CMakeFiles/Projet_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alex\CLionProjects\projetC_S3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Projet_c.dir/timer.c.obj"
	C:\Users\alex\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Projet_c.dir/timer.c.obj -MF CMakeFiles\Projet_c.dir\timer.c.obj.d -o CMakeFiles\Projet_c.dir\timer.c.obj -c C:\Users\alex\CLionProjects\projetC_S3\timer.c

CMakeFiles/Projet_c.dir/timer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Projet_c.dir/timer.c.i"
	C:\Users\alex\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alex\CLionProjects\projetC_S3\timer.c > CMakeFiles\Projet_c.dir\timer.c.i

CMakeFiles/Projet_c.dir/timer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Projet_c.dir/timer.c.s"
	C:\Users\alex\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alex\CLionProjects\projetC_S3\timer.c -o CMakeFiles\Projet_c.dir\timer.c.s

CMakeFiles/Projet_c.dir/rdv.c.obj: CMakeFiles/Projet_c.dir/flags.make
CMakeFiles/Projet_c.dir/rdv.c.obj: C:/Users/alex/CLionProjects/projetC_S3/rdv.c
CMakeFiles/Projet_c.dir/rdv.c.obj: CMakeFiles/Projet_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alex\CLionProjects\projetC_S3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Projet_c.dir/rdv.c.obj"
	C:\Users\alex\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Projet_c.dir/rdv.c.obj -MF CMakeFiles\Projet_c.dir\rdv.c.obj.d -o CMakeFiles\Projet_c.dir\rdv.c.obj -c C:\Users\alex\CLionProjects\projetC_S3\rdv.c

CMakeFiles/Projet_c.dir/rdv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Projet_c.dir/rdv.c.i"
	C:\Users\alex\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alex\CLionProjects\projetC_S3\rdv.c > CMakeFiles\Projet_c.dir\rdv.c.i

CMakeFiles/Projet_c.dir/rdv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Projet_c.dir/rdv.c.s"
	C:\Users\alex\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alex\CLionProjects\projetC_S3\rdv.c -o CMakeFiles\Projet_c.dir\rdv.c.s

CMakeFiles/Projet_c.dir/agenda.c.obj: CMakeFiles/Projet_c.dir/flags.make
CMakeFiles/Projet_c.dir/agenda.c.obj: C:/Users/alex/CLionProjects/projetC_S3/agenda.c
CMakeFiles/Projet_c.dir/agenda.c.obj: CMakeFiles/Projet_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alex\CLionProjects\projetC_S3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Projet_c.dir/agenda.c.obj"
	C:\Users\alex\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Projet_c.dir/agenda.c.obj -MF CMakeFiles\Projet_c.dir\agenda.c.obj.d -o CMakeFiles\Projet_c.dir\agenda.c.obj -c C:\Users\alex\CLionProjects\projetC_S3\agenda.c

CMakeFiles/Projet_c.dir/agenda.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Projet_c.dir/agenda.c.i"
	C:\Users\alex\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alex\CLionProjects\projetC_S3\agenda.c > CMakeFiles\Projet_c.dir\agenda.c.i

CMakeFiles/Projet_c.dir/agenda.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Projet_c.dir/agenda.c.s"
	C:\Users\alex\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alex\CLionProjects\projetC_S3\agenda.c -o CMakeFiles\Projet_c.dir\agenda.c.s

# Object files for target Projet_c
Projet_c_OBJECTS = \
"CMakeFiles/Projet_c.dir/main.c.obj" \
"CMakeFiles/Projet_c.dir/cell.c.obj" \
"CMakeFiles/Projet_c.dir/list.c.obj" \
"CMakeFiles/Projet_c.dir/timer.c.obj" \
"CMakeFiles/Projet_c.dir/rdv.c.obj" \
"CMakeFiles/Projet_c.dir/agenda.c.obj"

# External object files for target Projet_c
Projet_c_EXTERNAL_OBJECTS =

Projet_c.exe: CMakeFiles/Projet_c.dir/main.c.obj
Projet_c.exe: CMakeFiles/Projet_c.dir/cell.c.obj
Projet_c.exe: CMakeFiles/Projet_c.dir/list.c.obj
Projet_c.exe: CMakeFiles/Projet_c.dir/timer.c.obj
Projet_c.exe: CMakeFiles/Projet_c.dir/rdv.c.obj
Projet_c.exe: CMakeFiles/Projet_c.dir/agenda.c.obj
Projet_c.exe: CMakeFiles/Projet_c.dir/build.make
Projet_c.exe: CMakeFiles/Projet_c.dir/linkLibs.rsp
Projet_c.exe: CMakeFiles/Projet_c.dir/objects1.rsp
Projet_c.exe: CMakeFiles/Projet_c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\alex\CLionProjects\projetC_S3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable Projet_c.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Projet_c.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Projet_c.dir/build: Projet_c.exe
.PHONY : CMakeFiles/Projet_c.dir/build

CMakeFiles/Projet_c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Projet_c.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Projet_c.dir/clean

CMakeFiles/Projet_c.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\alex\CLionProjects\projetC_S3 C:\Users\alex\CLionProjects\projetC_S3 C:\Users\alex\CLionProjects\projetC_S3\cmake-build-debug C:\Users\alex\CLionProjects\projetC_S3\cmake-build-debug C:\Users\alex\CLionProjects\projetC_S3\cmake-build-debug\CMakeFiles\Projet_c.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Projet_c.dir/depend

