// multidimArrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	const int numRows{ 10 };
	const int numColumns{ 10 };
	int array[numRows][numColumns]{ 0 };
	for (int row = 0; row < numRows; ++row)
	{
		for (int column = 0; column < numColumns; ++column)
		{
			array[row][column] = row * column;
		}
	}
	for (int row = 1; row < numRows; row++)
	{
		for (int column = 1; column < numColumns; column++)
		{
			std::cout << array[row][column] << "\t";
		}
		std::cout << "\n";
	}

	//TO keep the cmd open
	while (true);
    return 0;
}

