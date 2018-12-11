#pragma once
#include"ICommand.h"

class RightArrowCommand : public ICommand
{
public:
	RightArrowCommand(Cell* cell, Cell start, int width)
	{
		this->cell = cell;
		this->start = start;
		this->width = width;
	}

	virtual void Execute()
	{
		if (cell->GetX() < start.GetX() + width-1)
		{
			cell->MoveRight();
		}
	}
private:
	Cell* cell;
	Cell start;
	int width;
};