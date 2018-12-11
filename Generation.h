#pragma once
#include<iostream>
#include<string>
#include"Cell.h"
#include <Windows.h>

using namespace std;

class Generation
{
public:
	Generation()
	{
		generation = "Generation";
		number = 0;
	}
	void Update()
	{
		number++;
	}
	void Print()
	{
		static const HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD coord = { (short)0, (short)0};
		SetConsoleCursorPosition(outputHandle, coord);
		cout << generation << " ";
		SetConsoleTextAttribute(outputHandle, 1);
		cout << number;
	}
private:
	string generation;	
	int number;
};