#include "Maze.h"

int Maze::IntRandom(int floor, int ceiling)
{
	srand(time(NULL));
	return (rand() % (ceiling-floor+1)) + floor;
}



void Maze::MazeGenerator(Point step)
{
	int direction[4] = { 0,1,2,3 };
	std::random_shuffle(&direction[0], &direction[4]);
	system("CLS");
	Print();

	for (int i = 0; i < 4; i++)
	{ DUPA
		switch (direction[i])
		{
		case 0:
			if (step.y - 2 <=  0 && step.y - 2 !='E')
				break;
			if (maze[((step.y - 2) * width) + step.x] == 0)
				break;
			maze[((step.y - 1) * width) + step.x] = 0;
			maze[((step.y - 2) * width) + step.x] = 0;
			MazeGenerator({ step.x, step.y - 2 });
			break;
		case 1:
			if (step.x + 2 >= width-1 && step.x +2 !='E')
				break;
			if (maze[((step.y) * width) + step.x + 2] == 0)
				break;
			maze[((step.y) * width) + step.x + 1] = 0;
			maze[((step.y) * width) + step.x + 2] = 0;
			MazeGenerator({ step.x + 2, step.y });
			break;
		case 2:
			if (step.y + 2 >= height-1 && step.y + 2 != 'E')
				break;
			if (maze[((step.y + 2) * width) + step.x] == 0)
				break;
			maze[((step.y + 1) * width) + step.x] = 0;
			maze[((step.y + 2) * width) + step.x] = 0;
			MazeGenerator({ step.x, step.y + 2 });
			break;
		case 3:
			if (step.x - 2 <= 0 && step.x + 2 != 'E')
				break;
			if (maze[((step.y) * width) + step.x - 2] == 0)
				return;
			maze[((step.y) * width) + step.x - 1] = 0;
			maze[((step.y) * width) + step.x - 2] = 0;
			MazeGenerator({ step.x - 2, step.y });
			break;
		}
		

	}

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
	
	int squareSide = IntRandom(3, std::min(height, width) - 2); //Docelowo zmienic na wymiar uzaleniony od wielkosci labiryntu
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
	if (height < 5|| width < 5 )
	{
		std::cout << "Nither height nor width can be smaller than 5" << std::endl;
		return;
	}
	else if (exitNumber == 0 || exitNumber > 4)
	{
		std::cout << "Exit number must be higher than 0 and smaller than 5!" << std::endl;
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
	//CenterSquereGenerator();

	maze[width * (height / 2) + (width / 2)] = 'S';
	MazeGenerator(Center);

}

int Maze::SetHeight(int _height)
{
	if (_height < 4)
	{
		std::cout << "Height must be bigger than 4!" << std::endl;
		return -1;
	}

	height = _height;
	return 0;
}

int Maze::SetWidth(int _width)
{
	if (_width < 5)
	{
		std::cout << "Width must be bigger than 4!" << std::endl;
		return 1;
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
