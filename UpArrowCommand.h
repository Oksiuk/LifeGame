#pragma once
#include"ICommand.h"

class UpArrowCommand : public ICommand
{
public:
	UpArrowCommand(Cell* cell, Cell start)
	{
		this->cell = cell;
		this->start = start;
		this->height = height;
	}
	virtual void Execute()
	{
		if (cell->GetY() > start.GetY())
		{
			cell->MoveUp();
		}
	}

private:
	Cell* cell;
	Cell start;
	int height;
};