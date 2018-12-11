#pragma once

#include"Caretaker.h"
#include"Cell.h"
#include"Generation.h"
#include"ICommand.h"
#include"Key.h"
#include"Memento.h"

using namespace std;

class Universe
{
	friend class DrawManager;
	friend class Memento;

public:
	Universe();
	int GetWidth();
	int GetHeight();
	Cell GetStart();
	int CountAliveNear(Cell* cell);
	void CreateFirstGeneration(Cell& cell, Key key);
	void CreateNextGeneration();
	bool FirstGenerationIsCompleted();	
	bool HasLife();
	bool NextGenerationIsEqualToPrevious();
	Memento& CreateMemento(Memento* memento);	
	~Universe();
	bool operator==(const Memento& source);
	
private:
	Cell * Array[10][40];
	Cell * NextArray[10][40];
	ICommand* command = nullptr;
	int width;
	int height;
	Cell startCell;
	Caretaker caretaker;
	Generation generation;
};