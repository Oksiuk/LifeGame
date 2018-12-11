#pragma once
#include<cstdlib>
#include"DrawManager.h"
#include"ReadKey.h"
#include"Universe.h"

class GameManager
{
public:
	
	void Start()
	{	
		ConsoleManager consoleManager(universe.GetStart());

		DrawManager drawManager(&consoleManager, &universe);

		drawManager.DrawBorder();
		
		while(!universe.FirstGenerationIsCompleted())
		{		
			Cell start(universe.GetStart());
			consoleManager.SetCursorPosition(start);

			while (start.Exists() != true)
			{
				system("cls");

				drawManager.DrawBorder();
				drawManager.DrawUniverse();
				drawManager.DrawCell(&start);

				Key key;
				ReadKey readKey(key);
				key = readKey.Read();

				universe.CreateFirstGeneration(start, key);
				drawManager.DrawCell(&start);

				Sleep(300);
			}
		}
		
		bool gameOver = false;

		while (!gameOver)
		{
			system("cls");

			drawManager.DrawBorder();
			drawManager.DrawUniverse();

			Memento memento;
			caretaker.AddMemento(universe.CreateMemento(&memento));

			universe.CreateNextGeneration();
			drawManager.DrawUniverse();

			gameOver = GameOver();

			Sleep(300);
		} 

		if (gameOver)
		{
			if (universe.HasLife() == false)
			{
				cout << "Universe dies because it doesn't has life anymore";
			}
			
			if (universe.NextGenerationIsEqualToPrevious()==true)
			{
				cout << "Universe dies because it's next generation is equal to previous";
			}
			else 
			{
				cout << "Universe dies because it replicates generation # " << generation;
			}
		}			
	}
	
	bool GameOver()
	{
	    bool gameOver = false;
		
		if (universe.HasLife() == false)
		{
			gameOver = true;
			return gameOver;
			
		}
		if (universe.NextGenerationIsEqualToPrevious()==true)
		{
			gameOver = true;
			return gameOver;
			
		}	
		for (int i = 0; i < caretaker.GetSize(); ++i)
		{
			if (universe == caretaker.RestoreMemento(i))
			{
				generation = i;
				gameOver = true;
				return gameOver;
			}
		}		
		return gameOver;
	}
	
private:
	Universe universe;
	Caretaker caretaker;
	int generation = 0;
};