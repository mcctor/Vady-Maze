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

	VadyMaze(const VadyMaze<T>& other_layout);
	VadyMaze<T>& operator=(const VadyMaze<T>& other_layout);

	VadyMaze(VadyMaze<T>&& other_layout);
	VadyMaze<T>& operator=(VadyMaze<T>&& other_layout);

	VadyMaze<T>& wrap_once();
	VadyMaze<T>& wrap_multi(int iterations = 1);

	int room_cnt();
};

// TODO: Reference additional headers your program requires here.
