// arrayTwo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	int array[]{1, 6, 7, 8, 9, 2, 4, 5, 3};
	int numberOfElements = sizeof(array) / sizeof(array[0]);
	for (int index = 0; index < numberOfElements; ++index)
		std::cout << array[index] << "\n";
	int number{ 0 };
	do
	{
		std::cout << "Enter a number between 1 and 9: ";
		std::cin >> number;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
	} while ((number > 9) || (number < 1));
	std::cin.ignore(32767, '\n');
	for (int index = 0; index < numberOfElements; ++index)
	{
		if (number == array[index])
		{
			std::cout << "The index is: " << index << "\n";
			break;
		}
	}


	//To keep the cmd open
	while (true);

    return 0;
}

