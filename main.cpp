#include"Maze.h"


int main()
{
	

	

	Maze* test = new Maze(30, 30, 1);
	test->GenerteMaze();
	test->Print();



	delete test;

	std::cin.get();


}