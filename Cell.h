#pragma once

class Cell
{
public:
	Cell();
	Cell(int x, int y);
	Cell(const Cell& source);

	int GetX();
	int GetY();
	void SetX(int x);
	void SetY(int y);

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	void ChangeState();

	bool IsAlive();
	bool IsStart();
	bool Exists();

	void SetExistance();
	void SetLiving();
	void DeleteLiving();
	void DeleteExistance();

	void PrintCell();
	void PrintBorderCell(char symbol);

	Cell& operator=(const Cell& source);
	bool operator==(const Cell& source);

private:
	int x;
	int y;
	bool isAlive = false;
	bool exists = false;
	bool start = true;
};
