#pragma once
#include"ConsoleManager.h"
#include"Universe.h"

class DrawManager
{
public:
	DrawManager(ConsoleManager* manager, Universe*universe)
	{
		this->consoleManager = manager;
		this->universe = universe;
	}
	
	void DrawGeneration()
	{
		universe->generation.Print();
	}
	void DrawBorder()
	{

		for (int i = 0; i <= universe->width; ++i)
		{
			Cell higherLine;
			higherLine.SetX(universe->startCell.GetX() - 1 + i);
			higherLine.SetY(universe->startCell.GetY() - 1);

			consoleManager->DrawAt('+', &higherLine);
		}
		for (int i = 0; i < universe->width + 2; ++i)
		{
			Cell lowerLine;
			lowerLine.SetX(universe->startCell.GetX() - 1 + i);
			lowerLine.SetY(universe->startCell.GetY() + universe->height);

			consoleManager->DrawAt('+', &lowerLine);
		}

		for (int i = 0; i < universe->height; ++i)
		{
			Cell leftLine;
			leftLine.SetX(universe->startCell.GetX() - 1);
			leftLine.SetY(universe->startCell.GetY() + i);

			consoleManager->DrawAt('+', &leftLine);
		}

		for (int i = 0; i <= universe->height; ++i)
		{
			Cell rightLine;
			rightLine.SetX(universe->startCell.GetX() - 1 + universe->width + 1);
			rightLine.SetY(universe->startCell.GetY() + i - 1);

			consoleManager->DrawAt('+', &rightLine);
		}
	}

	void DrawCell(Cell* cell)
	{
		if (cell != nullptr)
		{
			consoleManager->DrawAt(cell);
		}
	}
	void DrawUniverse()
	{
		DrawGeneration();
		for (int i = 0; i < universe->height;++i)
		{
			for (int j = 0; j < universe->width; ++j)
			{
				if (universe->Array[i][j]->Exists())
				{
					consoleManager->DrawAt(universe->Array[i][j]);
				}
			}
		}
	}

private:
	ConsoleManager * consoleManager;
	Universe* universe;
	
};