#include"Maze.h"


int main()
{
	srand(time(NULL));

	

	Maze* test = new Maze(16, 16, 1);
	test->GenerteMaze();
	test->Print();



	delete test;

	std::cin.get();


}