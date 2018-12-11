#pragma once
#include <iostream>
#include <Windows.h>
#include"Cell.h"
#include"Key.h"

using namespace std;

class ConsoleManager
{
public:
	ConsoleManager(Cell cell)
	{
		this->cell = cell;
	}

	void DrawAt(const char symbol, Cell* cell)
	{
		SetCursorPosition(*cell);
		cell->PrintBorderCell(symbol);
	}

	void DrawAt(Cell* cell)
	{
		SetCursorPosition(*cell);
		cell->PrintCell();
		
	}

	void SetCursorPosition(Cell& cell)
	{
		static const HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD coord = { (short)cell.GetX(), (short)cell.GetY() };
		SetConsoleCursorPosition(outputHandle, coord);
	}

private:
	Cell cell;
};