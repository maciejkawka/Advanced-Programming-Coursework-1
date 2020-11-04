#include "Maze.h"

int Maze::IntRandom(int floor, int ceiling)
{
	
	return (rand() % (ceiling-floor+1)) + floor;
}

void Maze::SuffleArray(int *arra)
{
	
	for (int i = 3; i > 0; i--)
	{
		int j = rand() % (i + 1);
		std::swap(arra[i], arra[j]);
	}
}



void Maze::MazeGenerator(Point step)
{
	system("CLS");
	Print();
		int direction[4] = { 0,1,2,3 };
		SuffleArray(direction);


		for (int i = 0; i < 4; i++)
		{
			switch (direction[i])
			{
			case 0:
				if (step.y - 2 <= 0)
					continue;
				if (maze[((step.y - 2) * width) + step.x] == 0)
					continue;
				maze[((step.y - 1) * width) + step.x] = 0;
				maze[((step.y - 2) * width) + step.x] = 0;
				MazeGenerator({ step.x, step.y - 2 });
				break;
			case 1:
				if (step.x + 2 >= width - 1)
					continue;
				if (maze[((step.y) * width) + step.x + 2] == 0)
					continue;
				maze[((step.y) * width) + step.x + 1] = 0;
				maze[((step.y) * width) + step.x + 2] = 0;
				MazeGenerator({ step.x + 2, step.y });
				break;
			case 2:
				if (step.y + 2 >= height - 1)
					continue;
				if (maze[((step.y + 2) * width) + step.x] == 0)
					continue;
				maze[((step.y + 1) * width) + step.x] = 0;
				maze[((step.y + 2) * width) + step.x] = 0;
				MazeGenerator({ step.x, step.y + 2 });
				break;
			case 3:
				if (step.x - 2 <= 0)
					continue;
				if (maze[((step.y) * width) + step.x - 2] == 0)
					continue;
				maze[((step.y) * width) + step.x - 1] = 0;
				maze[((step.y) * width) + step.x - 2] = 0;
				MazeGenerator({ step.x - 2, step.y });
				break;
			}





		}
		
	


}


bool Maze::PatchFinder(Point step)
{  
	if (step.x<0 || step.x>width - 1 || step.y<0 || step.y>height - 1)
		return false;
	if (maze[((step.y) * width) + step.x] == 'X' || maze[((step.y) * width) + step.x] == 'o')
		return false;
	if (maze[((step.y) * width) + step.x] == 'S')
		return true;

	maze[((step.y) * width) + step.x] = 'o';
	system("CLS");
	Print();


	Point vector;
	vector.x = Center.x - step.x;
	vector.y = -Center.y - step.y;

	if (vector.x <= 0 && vector.y < 0)
	{
		if (PatchFinder({ step.x, step.y + 1 }) == true) return true;
		if (PatchFinder({ step.x - 1, step.y }) == true)  return true;
		if (PatchFinder({ step.x, step.y - 1 }) == true)  return true;
		if (PatchFinder({ step.x + 1  , step.y }) == true)  return true;
	}
	else if (vector.x < 0 && vector.y >= 0)
	{
		if (PatchFinder({ step.x - 1, step.y }) == true)  return true;
		if (PatchFinder({ step.x, step.y - 1 }) == true)  return true;
		if (PatchFinder({ step.x, step.y + 1 }) == true)  return true;
		if (PatchFinder({ step.x + 1  , step.y }) == true)  return true;
	}
	else if (vector.x >= 0 && vector.y > 0)
	{
		if (PatchFinder({ step.x, step.y - 1 }) == true)   return true;
		if (PatchFinder({ step.x + 1  , step.y }) == true)  return true;
		if (PatchFinder({ step.x - 1, step.y }) == true)  return true;
		if (PatchFinder({ step.x, step.y + 1 }) == true)  return true;
	}
	else if (vector.x > 0 && vector.y <= 0)
	{
		if (PatchFinder({ step.x + 1  , step.y }) == true)  return true;
		if (PatchFinder({ step.x, step.y + 1 }) == true)  return true;
		if (PatchFinder({ step.x, step.y - 1 }) == true)  return true;
		if (PatchFinder({ step.x - 1, step.y }) == true)  return true;
	}

	maze[((step.y) * width) + step.x] = 0;

	return false;
	
}

void Maze::ExitPointPlacement()
{
	Exit = new Point[exitNumber];

	for (int i = 0; i < exitNumber; i++)
	{
		switch (i)
		{
		case 0:
			Exit[i].x = 1;
			Exit[i].y = 0;
			break;
		case 1:
			Exit[i].x = width - 1;
			Exit[i].y = 1;
			break;
		case 2:
			Exit[i].x = 0;
			Exit[i].y = height - 2;
			break;
		case 3:
			Exit[i].x = width - 2;
			Exit[i].y = height - 1;
			break;
		default:
			std::cout << "Error: ExitNumber to big" << std::endl;
			break;
		}

		maze[Exit[i].y * width + Exit[i].x] = 'E';
	}
}

void Maze::CenterSquereGenerator()
{
	int squareSide = IntRandom(3, std::min(height, width) - 5);
	int squareCenter = squareSide * (squareSide / 2) + (squareSide / 2);
	int mazeCenter = Center.x+(Center.y)*width;

	int startPoint = mazeCenter - (squareCenter % squareSide) - width * (squareSide/2);
	for (int i=0; i<squareSide;i++)
	{
		for (int j = 0; j < squareSide; j++)
			maze[startPoint + i * width + j] = 0;
	}
}



Maze::Maze() : height(0), width(0), exitNumber(0), maze(nullptr), Exit(nullptr)
{
	Center.x = 0;
	Center.y = 0;
}

Maze::Maze(int _height, int _width, int _extitNumber) :height(_height), width(_width), exitNumber(_extitNumber), maze(nullptr), Exit(nullptr)
{
	Center.x = 0;
	Center.y = 0;
}

Maze::~Maze()
{
	delete[] Exit;
	delete[] maze;
}

void Maze::GenerteMaze()
{
	if (height < 8|| width < 8 )
	{
		std::cout << "Nither height nor width can be smaller than 8" << std::endl;
		return;
	}
	else if (height % 2 == 0 || width % 2 == 0)
	{
		std::cout << "Nither height nor width can be even" << std::endl;
		return;
	}
	else if (exitNumber == 0 || exitNumber > 4)
	{
		std::cout << "Exit number must be higher than 0 and smaller than 8!" << std::endl;
		return;
	}
	else if (maze != nullptr)
	{
		std::cout << "Maze has been already generated" << std::endl;
		return;
	}

	maze = new char[height * width];
	for (int i = 0; i < height * width; i++)
		maze[i] = 'X';
	
	Center.y = height / 2;
	Center.x = width / 2;

	
	

	
	
	ExitPointPlacement();
	MazeGenerator({ 1,1 });
	CenterSquereGenerator();
	
	
	maze[width * (height / 2) + (width / 2)] = 'S';
	for(int i=0;i<exitNumber;i++)
		PatchFinder(Exit[i]);
}

int Maze::SetHeight(int _height)
{
	if (_height % 2 == 0)
	{
		std::cout << "Height cannot be even!" << std::endl;
		return -1;
	}
	if (_height < 8)
	{
		std::cout << "Height must be bigger than 7!" << std::endl;
		return -1;
	}

	height = _height;
	return 0;
}

int Maze::SetWidth(int _width)
{
	if (_width % 2 == 0)
	{
		std::cout << "Width cannot be even!" << std::endl;
		return -1;
	}
	if (_width < 8)
	{
		std::cout << "Width must be bigger than 7!" << std::endl;
		return -1;
	}

	width = _width;
	return 0;
}

int Maze::SetExitNumber(int _exitNumber)
{
	if (_exitNumber < 0 || _exitNumber>4)
	{
		std::cout << "Exit number must be bigger than 0 and smaller than 5!" << std::endl;
		return 1;
	}

	exitNumber = _exitNumber;
	return 0;
}

void Maze::Print()
{
	if (maze == nullptr)
	{
		std::cout << "Maze is not generated!!" << std::endl;
		return;
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			std::cout << maze[i * width + j];
		std::cout << std::endl;
	}
}
