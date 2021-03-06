// descendingSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

int main()
{
	const int length{ 5 };
	int array[length] = { 30, 50, 20, 10, 40 };

	for (int index = 0; index < length; index++)
	{
		std::cout << array[index] << " ";
	}
	std::cout << "\n";

	for (int startIndex{ 0 }; startIndex < (length - 1); ++startIndex)
	{
		int largestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			if (array[largestIndex]<array[currentIndex])
			{
				largestIndex = currentIndex;
			}
		}
		std::swap(array[startIndex], array[largestIndex]);
	}
	for (int index = 0; index < length; ++index)
	{
		std::cout << array[index] << " ";
	}

	//TO keep the cmd open
	while (true);
    return 0;
}

