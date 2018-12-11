#pragma once
#include"ICommand.h"

class SpaceCommand : public ICommand
{
public:
	SpaceCommand(Cell* cell)
	{
		this->cell = cell;
	}
	virtual void Execute()
	{
		cell->SetExistance();
	}
private:
	Cell* cell;
};