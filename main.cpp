#include"Maze.h"


int main()
{
	

	

	Maze* test = new Maze(20, 20, 1);
	test->GenerteMaze();
	test->Print();



	delete test;

	std::cin.get();


}