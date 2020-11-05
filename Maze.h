#pragma once
#include<iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include<algorithm>
#include<vector>
#include <fstream>
#include<string>

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
	std::vector<Point>* path;

	int GetRandomInt(int floor, int ceiling);
	void SuffleArray(int*arra);
	void RecursiveMazeGenerator(Point step);
	bool RecursivePathFinder(Point step);
	void PlaceExits();
	void CenterSquereGenerator();


public:
	Maze();
	Maze(int _height, int _width, int _extiNumber);
	~Maze();
	void GenerteMaze();
	int SetHeight(int _height);
	int SetWidth(int _width);
	int SetExitNumber(int _exitNumber);
	void Print() const;
	inline int GetHeight() const { return height; }
	inline int GetWidht() const { return width; }
	inline int GetExitNumer() const { return exitNumber; }



	void LoadMaze(std::string filePath);
	void SaveMaze(std::string filePath) const;





};
