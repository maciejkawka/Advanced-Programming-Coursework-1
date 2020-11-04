#pragma once
#include<iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include<algorithm>

struct Point {

	int x;
	int y;
};

class Maze {

private:

	int height;
	int width;
	int exitNumber;
	Point* Exit;
	Point Center;
	char* maze;
	

	int IntRandom(int floor, int ceiling);
	void SuffleArray(int*arra);
	void MazeGenerator(Point step);
	bool PatchFinder(Point step);
	void ExitPointPlacement();
	void CenterSquereGenerator();

public:
	Maze();
	Maze(int _height, int _width, int _extiNumber); // Zobaczymy czy nie wywaliæ
	~Maze();
	void GenerteMaze();
	int SetHeight(int _height);
	int SetWidth(int _width);
	int SetExitNumber(int _exitNumber);
	void Print();

	inline int GetHeight() const { return height; }
	inline int GetWidht() const { return width; }
	inline int GetExitNumer() const { return exitNumber; }



	void LoadMaze(std::string fileName);
	void SaveMaze(std::string fileName) const;





};
