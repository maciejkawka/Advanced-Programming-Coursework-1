#include"Maze.h"


int main()
{
	srand(time(NULL));

	

	Maze* test = new Maze(21, 11, 3);

	test->GenerteMaze();
	test->Print();



	delete test;

	std::cin.get();


}