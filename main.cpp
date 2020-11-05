#include"Maze.h"


int main()
{
	srand(time(NULL));

	

	Maze* test = new Maze(19, 19, 3);
	test->GenerteMaze();
	test->Print();
	test->SaveMaze("1.txt");


	Maze* elo = new Maze();
	elo->LoadMaze("TEST.txt");
	elo->GenerteMaze();
	elo->Print();
	
	Maze* elo1 = new Maze();
	elo1->LoadMaze("1.txt");
	elo1->GenerteMaze();
	elo1->Print();


	delete test;

	std::cin.get();


}