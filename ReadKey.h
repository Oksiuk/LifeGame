#pragma once
#include <conio.h>
#include"Key.h"

class ReadKey
{
public:
	ReadKey(Key& key)
	{
		this->key = key;
	}

	Key Read()
	{
		int key = _getch();
		if (key == 224)
		{
			key = _getch();
		}

		return (Key)key;
	}
private:
	Key key;
};