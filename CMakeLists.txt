# CMakeList.txt : CMake project for Vady Maze, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Vady Maze")

# Add source to this project's executable.
add_library(vady_maze "Vady Maze.cpp")
add_executable (main "main.cpp" "Vady Maze.cpp")

target_link_libraries(main PUBLIC vady_maze)

# TODO: Add tests and install targets if needed.
