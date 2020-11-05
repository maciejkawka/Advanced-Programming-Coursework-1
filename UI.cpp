#include "UI.h"

void UI::Welcome()
{
	system("CLS");
	std::cout << "Maciej's Maze Generator!!" << std::endl <<"Select correct option"<<std::endl;

	std::cout << "1. Set Dimensions" << std::endl;
	std::cout << "2. Set Exits Number" << std::endl;
	std::cout << "3. Generate Maze with paths" << std::endl;
	std::cout << "4. Save Maze" << std::endl;
	std::cout << "5. Load Maze" << std::endl;
	std::cout << "6. Reset Maze" << std::endl;
	std::cout << "7. Exit" << std::endl;

}

void UI::Print()
{

	std::cout << "MAZE:" << std::endl << std::endl;
	mainMaze->Print();
}

int UI::InputInt()
{
	int input;
	do {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> input;
	} while (std::cin.fail());
	return input;
}

UI::UI(): mainMaze(nullptr)
{
	mainMaze = new Maze();
}

UI::~UI()
{
	delete mainMaze;
}

void UI::SetDimentions()
{

	system("CLS");
	std::cout << "Set Dimensions." << std::endl;
	std::cout << "Width: ";
	while (mainMaze->SetWidth(InputInt()));
	std::cout << "Height: ";
	while (mainMaze->SetHeight(InputInt()));
}

void UI::SetExitsNumber()
{
	system("CLS");
	std::cout << "Set Number of Exits" << std::endl;
	while (mainMaze->SetExitNumber(InputInt()));
}

void UI::GenerateMaze()
{
	system("CLS");
	mainMaze->GenerteMaze();
	system("pause");
}

void UI::Reset()
{
	system("CLS");
	mainMaze->Reset();
	system("pause");
}

void UI::Load()
{

	system("CLS");
	std::cout << "Enter tile name ";
	std::string input;
	std::cin >> input;
	input += ".txt";
	std::cout << "File name is " << input << std::endl;

	mainMaze->LoadMaze(input);
	system("pause");
}

void UI::Save()
{
	system("CLS");
	std::cout << "Enter tile name ";
	std::string input;
	std::cin >> input;
	input += ".txt";
	std::cout << "File name is " << input << std::endl;

	mainMaze->SaveMaze(input);
	system("pause");
}
