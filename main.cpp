#include <iostream>

#include "Vady Maze.h"


int main(int argc, char** argv) {
	VadyMaze<int> collection{};

	std::cout << collection.wrap_once().room_cnt() << std::endl;
}
