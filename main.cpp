#include"Maze.h"


int main()
{
	

	

	Maze* test = new Maze(10, 10, 1);
	test->GenerteMaze();
	test->Print();



	delete test;

	std::cin.get();


}