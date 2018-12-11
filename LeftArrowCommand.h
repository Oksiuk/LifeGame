#pragma once
#include"ICommand.h"

class LeftArrowCommand : public ICommand
{
public:
	LeftArrowCommand(Cell* cell, Cell start)
	{
		this->cell = cell;
		this->start = start;
	}
	virtual void Execute()
	{
		if (cell->GetX() > start.GetX())
		{
			cell->MoveLeft();
		}
	}
private:
	Cell* cell;
	Cell start;
};