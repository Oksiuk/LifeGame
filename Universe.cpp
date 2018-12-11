#include"stdafx.h"
#include <iostream>
#include <Windows.h>
#include"DownArrowCommand.h"
#include"EnterCommand.h"
#include"LeftArrowCommand.h"
#include"RightArrowCommand.h"
#include"SpaceCommand.h"
#include"Universe.h"
#include"UpArrowCommand.h"

Universe:: Universe()
{
	this->height = 10;
	this->width = 40;
	startCell.SetX(2);
	startCell.SetY(2);
	
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width;++j)
		{
			Array[i][j] = new Cell(startCell.GetX() + j, startCell.GetY() + i);
			NextArray[i][j] = new Cell(startCell.GetX() + j, startCell.GetY() + i);
		}
	}	
}

int Universe::GetWidth()
{
	return width;
}

int Universe::GetHeight()
{
	return height;
}

Cell Universe::GetStart()
{
	return startCell;
}

int Universe::CountAliveNear(Cell* cell)
{
	int j = cell->GetX() - startCell.GetX();
	int i = cell->GetY() - startCell.GetY();

	int count = 0;

	if (i > 0)
	{
		if (Array[i - 1][j]->IsAlive())
		{
			count++;
		}
	}
	if (j > 0)
	{
		if (Array[i][j - 1]->IsAlive())
		{
			count++;
		}
	}
	if (j < width - 1)
	{
		if (Array[i][j + 1]->IsAlive())
		{
			count++;
		}
	}
	if (i > 0 && j > 0)
	{
		if (Array[i - 1][j - 1]->IsAlive())
		{
			count++;
		}
	}
	if (i > 0 && j < width - 1)
	{
		if (Array[i - 1][j + 1]->IsAlive())
		{
			count++;
		}
	}
	if (i < height - 1 && j>0)
	{
		if (Array[i + 1][j - 1]->IsAlive())
		{
			count++;
		}
	}
	if (i < height - 1)
	{
		if (Array[i + 1][j]->IsAlive())
		{
			count++;
		}
	}
	if (i < height - 1 && j < width - 1)
	{
		if (Array[i + 1][j + 1]->IsAlive())
		{
			count++;
		}
	}
	return count;
}

void Universe::CreateFirstGeneration(Cell& cell, Key key)
{
	switch (key)
	{
	case Key::Up:
	{
		command = new UpArrowCommand(&cell, startCell);
		break;
	}
	case Key::Down:
	{
		command = new DownArrowCommand(&cell, startCell, height);
		break;
	}
	case Key::Left:
	{
		command = new LeftArrowCommand(&cell, startCell);
		break;
	}
	case Key::Right:
	{
		command = new RightArrowCommand(&cell, startCell, width);
		break;
	}
	case Key::Enter:
	{
		command = new EnterCommand(&cell);
		break;
	}
	case Key::Space:
	{
		command = new SpaceCommand(&cell);

		int j = cell.GetX() - startCell.GetX();
		int i = cell.GetY() - startCell.GetY();

		if (Array[i][j]->Exists() == false)
		{
			if (cell.IsAlive())
			{
				Array[i][j]->SetLiving();
			}
			Array[i][j]->SetExistance();
			break;
		}
	}
	}
	if (command != nullptr)
	{
		command->Execute();
		delete command;
	}
}

void Universe::CreateNextGeneration()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width;++j)
		{
			int aliveNear = CountAliveNear(Array[i][j]);

			if (Array[i][j]->IsAlive() == false)
			{
				if (aliveNear == 3)
				{
					NextArray[i][j]->SetLiving();
					NextArray[i][j]->SetExistance();
				}
				else
				{
					NextArray[i][j]->SetExistance();
				}
			}
			else if (Array[i][j]->IsAlive())
			{
				if (aliveNear == 3 || aliveNear == 2)
				{
					NextArray[i][j]->SetLiving();
					NextArray[i][j]->SetExistance();
				}
				else if (aliveNear > 3 || aliveNear < 2)
				{
					NextArray[i][j]->DeleteLiving();
					NextArray[i][j]->SetExistance();
				}
			}
		}
	}
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width;++j)
		{
			if (NextArray[i][j]->IsAlive())
			{
				Array[i][j]->SetLiving();
			}
			else
			{
				Array[i][j]->DeleteLiving();
			}
		}
	}
	generation.Update();
}

bool Universe::FirstGenerationIsCompleted()
{
	bool isCompleted = false;
	int count = 0;

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width;++j)
		{
			if (Array[i][j]->Exists())
			{
				count++;
			}
		}
		if (count == height * width)
		{
			isCompleted = true;
		}
	}
	return isCompleted;
}

bool Universe::HasLife()
{
	bool haslife = false;

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width;++j)
		{
			if (Array[i][j]->IsAlive())
			{
				haslife = true;
				return haslife;
			}
		}
	}
	return haslife;
}

bool Universe::NextGenerationIsEqualToPrevious()
{
	bool equal = false;

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width;++j)
		{
			if (NextArray[i][j] == Array[i][j])
			{
				equal = true;
			}
			else
			{
				return false;
			}
		}
	}
	
	return equal;
}

Memento& Universe::CreateMemento(Memento* memento)
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			memento->Array[i][j] = *(Array[i][j]);
		}
	}
	return *memento;
}

Universe::	~Universe()
{
	for (int i = 0; i < height; ++i)
	{
		delete[]Array[i];
		delete[]NextArray[i];
	}
	delete[]Array;
	delete[] NextArray;
}

bool Universe:: operator==(const Memento& source)
{
	bool equal = false;
	
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width;++j)
		{
			if (*(Array[i][j]) == source.Array[i][j])
			{
				equal = true;
			}
			else
			{
				return false;;
			}
		}
	}
	return equal;
}