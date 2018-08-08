// game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

enum Weapons
{
	HELTH_POTION,
	TORCHES,
	ARROWS,
	TOTAL_ITEMS,
};

void countTotalItems(int array[])
{
	int totalItems{ 0 };
	for (int iii = 0; iii < TOTAL_ITEMS; ++iii)
	{
		totalItems += *(array + iii);
	}
	std::cout << "Player has " << totalItems << " items.";
}

int main()
{
	int array[TOTAL_ITEMS]{ 2, 5, 10 };
	countTotalItems(array);

	//To keep the cmd open
	while (true);
    return 0;
}

