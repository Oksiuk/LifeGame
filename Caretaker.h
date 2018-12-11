#pragma once
#include<vector>
#include"Memento.h"
using namespace std;

class Caretaker
{
public:
	void AddMemento(Memento& memento)
	{
		history.push_back(memento); 
	}
	int GetSize()
	{
		return history.size();
	}
	Memento& RestoreMemento(int i)
	{
		return history[i];
	}
	
private:
	vector<Memento>history;
};