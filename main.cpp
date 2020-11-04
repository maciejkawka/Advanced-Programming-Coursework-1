#include"Maze.h"


int main()
{
	srand(time(NULL));

	

	Maze* test = new Maze(9, 9, 4);

	test->GenerteMaze();
	test->Print();



	delete test;

	std::cin.get();


}