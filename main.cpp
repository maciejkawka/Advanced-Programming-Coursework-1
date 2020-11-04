#include"Maze.h"


int main()
{
	srand(time(NULL));

	

	Maze* test = new Maze(15, 15, 4);

	test->GenerteMaze();
	test->Print();



	delete test;

	std::cin.get();


}