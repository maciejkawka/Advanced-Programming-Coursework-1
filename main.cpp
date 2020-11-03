#include"Maze.h"


int main()
{
	

	

	Maze* test = new Maze(50, 50, 3);
	test->GenerteMaze();
	test->Print();



	delete test;

	std::cin.get();


}