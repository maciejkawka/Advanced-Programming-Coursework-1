#include"Maze.h"


int main()
{
	

	std::cout << 4 % 3 << std::endl;

	Maze* test = new Maze(6, 8, 3);
	test->GenerteMaze();
	test->Print();



	delete test;

	std::cin.get();


}