#pragma once
#include"ICommand.h"

class EnterCommand : public ICommand
{
public:
	EnterCommand(Cell* cell)
	{
		this->cell = cell;
	}
	virtual void Execute()
	{
		cell->ChangeState();
	}
private:
	Cell* cell;
};