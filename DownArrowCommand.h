#pragma once
#include"ICommand.h"

class DownArrowCommand : public ICommand
{
public:
	DownArrowCommand (Cell* cell, Cell start, int height)
	{
		this->cell = cell;
		this->start = start;
		this->height = height;
	}
	
	virtual void Execute()
	{
		if (cell->GetY() < start.GetY() + height-1)
		{
			cell->MoveDown();
		}
	}
private:
	Cell* cell;
	Cell start;
	int height;

};