// Vady Maze.cpp : Defines the entry point for the application.
//
#include <algorithm>

#include "Vady Maze.h"

template<typename T>
VadyMaze<T>::VadyMaze(const VadyMaze& other_obj) : layout_matrix{ other_obj.layout_matrix }, room_cnt{ layout_matrix.size() } {
}

template<typename T>
VadyMaze<T>& VadyMaze<T>::operator=(const VadyMaze& other_obj) {
	this = VadyMaze(other_obj);
	return this;
}

template<typename T>
VadyMaze<T>::VadyMaze(VadyMaze&& other_obj) {
	room_cnt = other_obj.room_cnt;
	layout_matrix = other_obj.layout_matrix;

	other_obj.layout_matrix = std::vector<std::vector<T>>{};
	other_obj.room_cnt = 0;
}

template<typename T>
VadyMaze<T>& VadyMaze<T>::operator=(VadyMaze&& other_obj) {
	this = VadyMaze(std::move(other_obj));
	return this;
}

template<typename T>
int VadyMaze<T>::new_rooms_to_wrap() {
	return std::sqrt(room_cnt) * 4 + 4;
}

template<typename T>
int VadyMaze<T>::enlarged_map_len() {
	return std::sqrt(new_rooms_to_wrap() + room_cnt);
}

template<typename T>
int VadyMaze<T>::room_cnt() {
	return room_cnt;
}

template<typename T>
VadyMaze<T>& VadyMaze<T>::wrap_once() {
	unsigned new_layout_len = enlarged_map_len();

	// above horizontal (going right)
	std::vector<T> head_array{};
	for (int i = 0; i < new_layout_len; ++i) {
		head_array.push_back(T{});
	}
	layout_matrix.insert(0, head_array);

	// right vertical (going down)
	for (int i = 1; i < new_layout_len - 1; ++i) {
		layout_matrix[i].push_back(T{});
	}

	// bottom horizontal (going left)
	std::vector<T> tail_array{};
	for (int i = 0; i < new_layout_len; ++i) {
		tail_array.push_back(T{});
	}
	std::reverse(tail_array.begin(), tail_array.end());
	layout_matrix.push_back(tail_array);

	// left vertical (going up)
	for (int i = new_layout_len - 2; i < 0; ++i) {
		layout_matrix[i].push_back(T{});
	}

	obj_count += new_layout_len;
	return this;
}

template<typename T>
VadyMaze<T>& VadyMaze<T>::wrap_multi(int iterations) {
	for (int i = 0; i < iterations; ++i) {
		wrap_once();
	}
	return this;
}
