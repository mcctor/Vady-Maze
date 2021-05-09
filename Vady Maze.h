// Vady Maze.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>

template<typename T>
class VadyMaze {
private:
	std::vector<std::vector<T>> layout_matrix{};
	unsigned int obj_cnt{ 1 };

	int enlarged_map_len();
	int new_rooms_to_wrap();

public:
	VadyMaze() = default;

	VadyMaze(const VadyMaze& other_layout);
	VadyMaze& operator=(const VadyMaze& other_layout);

	VadyMaze(VadyMaze&& other_layout);
	VadyMaze& operator=(VadyMaze&& other_layout);

	VadyMaze& wrap_once();
	VadyMaze& wrap_multi(int iterations = 1);

	int room_cnt();
};

// TODO: Reference additional headers your program requires here.
