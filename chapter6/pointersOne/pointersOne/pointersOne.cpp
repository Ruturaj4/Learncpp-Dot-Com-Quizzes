// pointersOne.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

void sortNames(std::string *ptr, int namesWanted)
{
	std::cout << "Here is your sorted list:\n";
	for (int inititalElement = 0; inititalElement < namesWanted - 1; ++inititalElement)
	{
		bool sorted{ false };
		for (int sortElement = 0; sortElement < namesWanted - inititalElement - 1; sortElement++)
		{
			if (ptr[sortElement] > ptr[sortElement + 1])
			{
				std::swap(ptr[sortElement], ptr[sortElement + 1]);
				sorted = true;
			}
		}
		if (!sorted)
			break;
	}
}

int main()
{
	int namesWanted;
	std::cout << "How many name do you want to enter? ";
	std::cin >> namesWanted;
	std::string *ptr = new std::string[namesWanted];
	int total{ 0 };
	while (total < namesWanted)
	{
		std::cout << "Enter name #" << total + 1 << ": ";
		std::cin >> *(ptr + total);
		++total;
	}
	sortNames(ptr, namesWanted);
	total = 0;
	while (total < namesWanted)
	{
		std::cout << "Name #" << total + 1 << ": " << *(ptr + total) << "\n";
		++total;
	}
	//Deleting the array
	delete[] ptr;

	//To keep the cmd open
	while (true);
    return 0;
}

