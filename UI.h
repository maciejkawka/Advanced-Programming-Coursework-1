#pragma once
#include<iostream>
#include"Maze.h"
#include<string>

class UI {

	Maze* mainMaze;
	
	inline int InputInt();

public:

	UI();
	~UI();
	void SetDimentions();
	void SetExitsNumber();
	void GenerateMaze();
	void Reset();
	void Load();
	void Save();
	void Welcome();
	void Print();







};