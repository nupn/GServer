# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/work/gserver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/work/gserver

# Include any dependencies generated for this target.
include CMakeFiles/Server.cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Server.cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Server.cpp.dir/flags.make

CMakeFiles/Server.cpp.dir/User.cpp.o: CMakeFiles/Server.cpp.dir/flags.make
CMakeFiles/Server.cpp.dir/User.cpp.o: User.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/work/gserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Server.cpp.dir/User.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.cpp.dir/User.cpp.o -c /home/ubuntu/work/gserver/User.cpp

CMakeFiles/Server.cpp.dir/User.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.cpp.dir/User.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/work/gserver/User.cpp > CMakeFiles/Server.cpp.dir/User.cpp.i

CMakeFiles/Server.cpp.dir/User.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.cpp.dir/User.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/work/gserver/User.cpp -o CMakeFiles/Server.cpp.dir/User.cpp.s

CMakeFiles/Server.cpp.dir/User.cpp.o.requires:

.PHONY : CMakeFiles/Server.cpp.dir/User.cpp.o.requires

CMakeFiles/Server.cpp.dir/User.cpp.o.provides: CMakeFiles/Server.cpp.dir/User.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server.cpp.dir/build.make CMakeFiles/Server.cpp.dir/User.cpp.o.provides.build
.PHONY : CMakeFiles/Server.cpp.dir/User.cpp.o.provides

CMakeFiles/Server.cpp.dir/User.cpp.o.provides.build: CMakeFiles/Server.cpp.dir/User.cpp.o


CMakeFiles/Server.cpp.dir/Process.cpp.o: CMakeFiles/Server.cpp.dir/flags.make
CMakeFiles/Server.cpp.dir/Process.cpp.o: Process.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/work/gserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Server.cpp.dir/Process.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.cpp.dir/Process.cpp.o -c /home/ubuntu/work/gserver/Process.cpp

CMakeFiles/Server.cpp.dir/Process.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.cpp.dir/Process.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/work/gserver/Process.cpp > CMakeFiles/Server.cpp.dir/Process.cpp.i

CMakeFiles/Server.cpp.dir/Process.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.cpp.dir/Process.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/work/gserver/Process.cpp -o CMakeFiles/Server.cpp.dir/Process.cpp.s

CMakeFiles/Server.cpp.dir/Process.cpp.o.requires:

.PHONY : CMakeFiles/Server.cpp.dir/Process.cpp.o.requires

CMakeFiles/Server.cpp.dir/Process.cpp.o.provides: CMakeFiles/Server.cpp.dir/Process.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server.cpp.dir/build.make CMakeFiles/Server.cpp.dir/Process.cpp.o.provides.build
.PHONY : CMakeFiles/Server.cpp.dir/Process.cpp.o.provides

CMakeFiles/Server.cpp.dir/Process.cpp.o.provides.build: CMakeFiles/Server.cpp.dir/Process.cpp.o


CMakeFiles/Server.cpp.dir/PacketHandler.cpp.o: CMakeFiles/Server.cpp.dir/flags.make
CMakeFiles/Server.cpp.dir/PacketHandler.cpp.o: PacketHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/work/gserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Server.cpp.dir/PacketHandler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.cpp.dir/PacketHandler.cpp.o -c /home/ubuntu/work/gserver/PacketHandler.cpp

CMakeFiles/Server.cpp.dir/PacketHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.cpp.dir/PacketHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/work/gserver/PacketHandler.cpp > CMakeFiles/Server.cpp.dir/PacketHandler.cpp.i

CMakeFiles/Server.cpp.dir/PacketHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.cpp.dir/PacketHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/work/gserver/PacketHandler.cpp -o CMakeFiles/Server.cpp.dir/PacketHandler.cpp.s

CMakeFiles/Server.cpp.dir/PacketHandler.cpp.o.requires:

.PHONY : CMakeFiles/Server.cpp.dir/PacketHandler.cpp.o.requires

CMakeFiles/Server.cpp.dir/PacketHandler.cpp.o.provides: CMakeFiles/Server.cpp.dir/PacketHandler.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server.cpp.dir/build.make CMakeFiles/Server.cpp.dir/PacketHandler.cpp.o.provides.build
.PHONY : CMakeFiles/Server.cpp.dir/PacketHandler.cpp.o.provides

CMakeFiles/Server.cpp.dir/PacketHandler.cpp.o.provides.build: CMakeFiles/Server.cpp.dir/PacketHandler.cpp.o


CMakeFiles/Server.cpp.dir/PacketProcessThread.cpp.o: CMakeFiles/Server.cpp.dir/flags.make
CMakeFiles/Server.cpp.dir/PacketProcessThread.cpp.o: PacketProcessThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/work/gserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Server.cpp.dir/PacketProcessThread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.cpp.dir/PacketProcessThread.cpp.o -c /home/ubuntu/work/gserver/PacketProcessThread.cpp

CMakeFiles/Server.cpp.dir/PacketProcessThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.cpp.dir/PacketProcessThread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/work/gserver/PacketProcessThread.cpp > CMakeFiles/Server.cpp.dir/PacketProcessThread.cpp.i

CMakeFiles/Server.cpp.dir/PacketProcessThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.cpp.dir/PacketProcessThread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/work/gserver/PacketProcessThread.cpp -o CMakeFiles/Server.cpp.dir/PacketProcessThread.cpp.s

CMakeFiles/Server.cpp.dir/PacketProcessThread.cpp.o.requires:

.PHONY : CMakeFiles/Server.cpp.dir/PacketProcessThread.cpp.o.requires

CMakeFiles/Server.cpp.dir/PacketProcessThread.cpp.o.provides: CMakeFiles/Server.cpp.dir/PacketProcessThread.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server.cpp.dir/build.make CMakeFiles/Server.cpp.dir/PacketProcessThread.cpp.o.provides.build
.PHONY : CMakeFiles/Server.cpp.dir/PacketProcessThread.cpp.o.provides

CMakeFiles/Server.cpp.dir/PacketProcessThread.cpp.o.provides.build: CMakeFiles/Server.cpp.dir/PacketProcessThread.cpp.o


CMakeFiles/Server.cpp.dir/TetrisProcess.cpp.o: CMakeFiles/Server.cpp.dir/flags.make
CMakeFiles/Server.cpp.dir/TetrisProcess.cpp.o: TetrisProcess.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/work/gserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Server.cpp.dir/TetrisProcess.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.cpp.dir/TetrisProcess.cpp.o -c /home/ubuntu/work/gserver/TetrisProcess.cpp

CMakeFiles/Server.cpp.dir/TetrisProcess.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.cpp.dir/TetrisProcess.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/work/gserver/TetrisProcess.cpp > CMakeFiles/Server.cpp.dir/TetrisProcess.cpp.i

CMakeFiles/Server.cpp.dir/TetrisProcess.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.cpp.dir/TetrisProcess.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/work/gserver/TetrisProcess.cpp -o CMakeFiles/Server.cpp.dir/TetrisProcess.cpp.s

CMakeFiles/Server.cpp.dir/TetrisProcess.cpp.o.requires:

.PHONY : CMakeFiles/Server.cpp.dir/TetrisProcess.cpp.o.requires

CMakeFiles/Server.cpp.dir/TetrisProcess.cpp.o.provides: CMakeFiles/Server.cpp.dir/TetrisProcess.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server.cpp.dir/build.make CMakeFiles/Server.cpp.dir/TetrisProcess.cpp.o.provides.build
.PHONY : CMakeFiles/Server.cpp.dir/TetrisProcess.cpp.o.provides

CMakeFiles/Server.cpp.dir/TetrisProcess.cpp.o.provides.build: CMakeFiles/Server.cpp.dir/TetrisProcess.cpp.o


CMakeFiles/Server.cpp.dir/LoginProcess.cpp.o: CMakeFiles/Server.cpp.dir/flags.make
CMakeFiles/Server.cpp.dir/LoginProcess.cpp.o: LoginProcess.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/work/gserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Server.cpp.dir/LoginProcess.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.cpp.dir/LoginProcess.cpp.o -c /home/ubuntu/work/gserver/LoginProcess.cpp

CMakeFiles/Server.cpp.dir/LoginProcess.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.cpp.dir/LoginProcess.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/work/gserver/LoginProcess.cpp > CMakeFiles/Server.cpp.dir/LoginProcess.cpp.i

CMakeFiles/Server.cpp.dir/LoginProcess.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.cpp.dir/LoginProcess.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/work/gserver/LoginProcess.cpp -o CMakeFiles/Server.cpp.dir/LoginProcess.cpp.s

CMakeFiles/Server.cpp.dir/LoginProcess.cpp.o.requires:

.PHONY : CMakeFiles/Server.cpp.dir/LoginProcess.cpp.o.requires

CMakeFiles/Server.cpp.dir/LoginProcess.cpp.o.provides: CMakeFiles/Server.cpp.dir/LoginProcess.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server.cpp.dir/build.make CMakeFiles/Server.cpp.dir/LoginProcess.cpp.o.provides.build
.PHONY : CMakeFiles/Server.cpp.dir/LoginProcess.cpp.o.provides

CMakeFiles/Server.cpp.dir/LoginProcess.cpp.o.provides.build: CMakeFiles/Server.cpp.dir/LoginProcess.cpp.o


CMakeFiles/Server.cpp.dir/LobbyProcess.cpp.o: CMakeFiles/Server.cpp.dir/flags.make
CMakeFiles/Server.cpp.dir/LobbyProcess.cpp.o: LobbyProcess.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/work/gserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Server.cpp.dir/LobbyProcess.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.cpp.dir/LobbyProcess.cpp.o -c /home/ubuntu/work/gserver/LobbyProcess.cpp

CMakeFiles/Server.cpp.dir/LobbyProcess.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.cpp.dir/LobbyProcess.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/work/gserver/LobbyProcess.cpp > CMakeFiles/Server.cpp.dir/LobbyProcess.cpp.i

CMakeFiles/Server.cpp.dir/LobbyProcess.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.cpp.dir/LobbyProcess.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/work/gserver/LobbyProcess.cpp -o CMakeFiles/Server.cpp.dir/LobbyProcess.cpp.s

CMakeFiles/Server.cpp.dir/LobbyProcess.cpp.o.requires:

.PHONY : CMakeFiles/Server.cpp.dir/LobbyProcess.cpp.o.requires

CMakeFiles/Server.cpp.dir/LobbyProcess.cpp.o.provides: CMakeFiles/Server.cpp.dir/LobbyProcess.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server.cpp.dir/build.make CMakeFiles/Server.cpp.dir/LobbyProcess.cpp.o.provides.build
.PHONY : CMakeFiles/Server.cpp.dir/LobbyProcess.cpp.o.provides

CMakeFiles/Server.cpp.dir/LobbyProcess.cpp.o.provides.build: CMakeFiles/Server.cpp.dir/LobbyProcess.cpp.o


CMakeFiles/Server.cpp.dir/msg.pb.cc.o: CMakeFiles/Server.cpp.dir/flags.make
CMakeFiles/Server.cpp.dir/msg.pb.cc.o: msg.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/work/gserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Server.cpp.dir/msg.pb.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.cpp.dir/msg.pb.cc.o -c /home/ubuntu/work/gserver/msg.pb.cc

CMakeFiles/Server.cpp.dir/msg.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.cpp.dir/msg.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/work/gserver/msg.pb.cc > CMakeFiles/Server.cpp.dir/msg.pb.cc.i

CMakeFiles/Server.cpp.dir/msg.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.cpp.dir/msg.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/work/gserver/msg.pb.cc -o CMakeFiles/Server.cpp.dir/msg.pb.cc.s

CMakeFiles/Server.cpp.dir/msg.pb.cc.o.requires:

.PHONY : CMakeFiles/Server.cpp.dir/msg.pb.cc.o.requires

CMakeFiles/Server.cpp.dir/msg.pb.cc.o.provides: CMakeFiles/Server.cpp.dir/msg.pb.cc.o.requires
	$(MAKE) -f CMakeFiles/Server.cpp.dir/build.make CMakeFiles/Server.cpp.dir/msg.pb.cc.o.provides.build
.PHONY : CMakeFiles/Server.cpp.dir/msg.pb.cc.o.provides

CMakeFiles/Server.cpp.dir/msg.pb.cc.o.provides.build: CMakeFiles/Server.cpp.dir/msg.pb.cc.o


CMakeFiles/Server.cpp.dir/CompletionQue.cpp.o: CMakeFiles/Server.cpp.dir/flags.make
CMakeFiles/Server.cpp.dir/CompletionQue.cpp.o: CompletionQue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/work/gserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Server.cpp.dir/CompletionQue.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.cpp.dir/CompletionQue.cpp.o -c /home/ubuntu/work/gserver/CompletionQue.cpp

CMakeFiles/Server.cpp.dir/CompletionQue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.cpp.dir/CompletionQue.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/work/gserver/CompletionQue.cpp > CMakeFiles/Server.cpp.dir/CompletionQue.cpp.i

CMakeFiles/Server.cpp.dir/CompletionQue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.cpp.dir/CompletionQue.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/work/gserver/CompletionQue.cpp -o CMakeFiles/Server.cpp.dir/CompletionQue.cpp.s

CMakeFiles/Server.cpp.dir/CompletionQue.cpp.o.requires:

.PHONY : CMakeFiles/Server.cpp.dir/CompletionQue.cpp.o.requires

CMakeFiles/Server.cpp.dir/CompletionQue.cpp.o.provides: CMakeFiles/Server.cpp.dir/CompletionQue.cpp.o.requires
	$(MAKE) -f CMakeFiles/Server.cpp.dir/build.make CMakeFiles/Server.cpp.dir/CompletionQue.cpp.o.provides.build
.PHONY : CMakeFiles/Server.cpp.dir/CompletionQue.cpp.o.provides

CMakeFiles/Server.cpp.dir/CompletionQue.cpp.o.provides.build: CMakeFiles/Server.cpp.dir/CompletionQue.cpp.o


# Object files for target Server.cpp
Server_cpp_OBJECTS = \
"CMakeFiles/Server.cpp.dir/User.cpp.o" \
"CMakeFiles/Server.cpp.dir/Process.cpp.o" \
"CMakeFiles/Server.cpp.dir/PacketHandler.cpp.o" \
"CMakeFiles/Server.cpp.dir/PacketProcessThread.cpp.o" \
"CMakeFiles/Server.cpp.dir/TetrisProcess.cpp.o" \
"CMakeFiles/Server.cpp.dir/LoginProcess.cpp.o" \
"CMakeFiles/Server.cpp.dir/LobbyProcess.cpp.o" \
"CMakeFiles/Server.cpp.dir/msg.pb.cc.o" \
"CMakeFiles/Server.cpp.dir/CompletionQue.cpp.o"

# External object files for target Server.cpp
Server_cpp_EXTERNAL_OBJECTS =

DEBUG/Server.cpp: CMakeFiles/Server.cpp.dir/User.cpp.o
DEBUG/Server.cpp: CMakeFiles/Server.cpp.dir/Process.cpp.o
DEBUG/Server.cpp: CMakeFiles/Server.cpp.dir/PacketHandler.cpp.o
DEBUG/Server.cpp: CMakeFiles/Server.cpp.dir/PacketProcessThread.cpp.o
DEBUG/Server.cpp: CMakeFiles/Server.cpp.dir/TetrisProcess.cpp.o
DEBUG/Server.cpp: CMakeFiles/Server.cpp.dir/LoginProcess.cpp.o
DEBUG/Server.cpp: CMakeFiles/Server.cpp.dir/LobbyProcess.cpp.o
DEBUG/Server.cpp: CMakeFiles/Server.cpp.dir/msg.pb.cc.o
DEBUG/Server.cpp: CMakeFiles/Server.cpp.dir/CompletionQue.cpp.o
DEBUG/Server.cpp: CMakeFiles/Server.cpp.dir/build.make
DEBUG/Server.cpp: CMakeFiles/Server.cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/work/gserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable DEBUG/Server.cpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Server.cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Server.cpp.dir/build: DEBUG/Server.cpp

.PHONY : CMakeFiles/Server.cpp.dir/build

CMakeFiles/Server.cpp.dir/requires: CMakeFiles/Server.cpp.dir/User.cpp.o.requires
CMakeFiles/Server.cpp.dir/requires: CMakeFiles/Server.cpp.dir/Process.cpp.o.requires
CMakeFiles/Server.cpp.dir/requires: CMakeFiles/Server.cpp.dir/PacketHandler.cpp.o.requires
CMakeFiles/Server.cpp.dir/requires: CMakeFiles/Server.cpp.dir/PacketProcessThread.cpp.o.requires
CMakeFiles/Server.cpp.dir/requires: CMakeFiles/Server.cpp.dir/TetrisProcess.cpp.o.requires
CMakeFiles/Server.cpp.dir/requires: CMakeFiles/Server.cpp.dir/LoginProcess.cpp.o.requires
CMakeFiles/Server.cpp.dir/requires: CMakeFiles/Server.cpp.dir/LobbyProcess.cpp.o.requires
CMakeFiles/Server.cpp.dir/requires: CMakeFiles/Server.cpp.dir/msg.pb.cc.o.requires
CMakeFiles/Server.cpp.dir/requires: CMakeFiles/Server.cpp.dir/CompletionQue.cpp.o.requires

.PHONY : CMakeFiles/Server.cpp.dir/requires

CMakeFiles/Server.cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Server.cpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Server.cpp.dir/clean

CMakeFiles/Server.cpp.dir/depend:
	cd /home/ubuntu/work/gserver && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/work/gserver /home/ubuntu/work/gserver /home/ubuntu/work/gserver /home/ubuntu/work/gserver /home/ubuntu/work/gserver/CMakeFiles/Server.cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Server.cpp.dir/depend

