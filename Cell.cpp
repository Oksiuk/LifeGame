#include"stdafx.h"
#include"Cell.h"
#include<iostream>
#include <Windows.h>

Cell::Cell() {};

Cell:: Cell(int x, int y)
	{
		this->x = x;
		this->y = y;
		isAlive = false;
		exists = false;
	}

Cell:: Cell(const Cell& source)
	{
		this -> x = source.x;
		this->y = source.y;
		this->isAlive = source.isAlive;
		this->exists = source.exists;
	}

int Cell:: GetX()
	{
		return x;
	}

int Cell:: GetY()
	{
		return y;
	}

void Cell:: SetX(int x)
	{
		this->x = x;
	}

void Cell:: SetY(int y)
	{
		this->y = y;
	}

void Cell::MoveLeft()
	{
		x -= 1;
	}

void Cell:: MoveRight()
	{
		x += 1;
	}

void Cell:: MoveUp()
	{
		y -= 1;
	}

void Cell:: MoveDown()
	{
		y += 1;
	}

void Cell::ChangeState()
	{
		if (isAlive == true)
		{
			isAlive = false;
		}
		else if (isAlive == false)
		{
			isAlive = true;
		}
	}

bool Cell::Exists()
{
	return exists;
}

bool::Cell::IsAlive()
{
	return isAlive;
}

bool Cell::IsStart()
{
	return start;
}

void Cell::SetExistance()
{
	start = false;
	exists = true;
}

void Cell::SetLiving()
{
	isAlive = true;
}

void Cell :: DeleteExistance()
{
	isAlive = false;
	exists = false;
}

void Cell::DeleteLiving()
{
	isAlive = false;
}

void Cell::PrintCell()
{
	static const HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	if (start == true) 
	{
		SetConsoleTextAttribute(outputHandle, 4);
		if (isAlive == false)
		{
			std::cout << 'X';
		}
		else if (isAlive == true)
		{
			std::cout << 'O';
		}
	}
	else
	{
		if (isAlive == true)
		{
			SetConsoleTextAttribute(outputHandle, 2);
			std::cout << 'O';
		}
		else if (isAlive == false)
		{
			SetConsoleTextAttribute(outputHandle, 15);
			std::cout << 'X';
		}
	}
}

void Cell::PrintBorderCell(char symbol)
{
	static const HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(outputHandle, 15);
	std::cout <<symbol;
}

Cell& Cell::operator=(const Cell& source)
{
	x = source.x;
	y = source.y;
	isAlive = source.isAlive;
	exists = source.exists;

	return *this;
}

bool Cell::operator==(const Cell& source)
{
	bool equal = false;
	if (x == source.x && y == source.y && isAlive == source.isAlive && exists==source.exists)
	{
		equal = true;
	}
	return equal;
}