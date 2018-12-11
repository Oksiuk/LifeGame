#pragma once
#include"Cell.h"

class ICommand
{
public:
	virtual void Execute() = 0;
};