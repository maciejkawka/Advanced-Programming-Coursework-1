#include"Maze.h"


int main()
{
	srand(time(NULL));

	

	Maze* test = new Maze(41, 17, 4);

	test->GenerteMaze();
	test->Print();



	delete test;

	std::cin.get();


}