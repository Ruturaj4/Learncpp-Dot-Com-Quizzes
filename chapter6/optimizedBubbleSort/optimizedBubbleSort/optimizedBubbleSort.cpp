// optimizedBubbleSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

int main()
{
	const int length{ 9 };
	int array[length] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };
	bool swapMade{ false };
	for (int initialIndex = 0; initialIndex < (length - 1); ++initialIndex)
	{
		for (int startIndex = 0; startIndex < (length - initialIndex - 1); ++startIndex)
		{
			if (array[startIndex] > array[startIndex + 1])
			{
				std::swap(array[startIndex], array[startIndex + 1]);
				swapMade = true;
			}
		}
		if (swapMade == false)
		{
			break;
			std::cout << "Early termination detection!\n";
		}
	}
	for (int index = 0; index < length; index++)
	{
		std::cout << array[index] << " ";
	}

	//To keep the cmd open
	while (true);

	return 0;
}
