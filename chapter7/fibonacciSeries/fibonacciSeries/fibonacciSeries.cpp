// fibonacciSeries.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int ficonacci(int count)
{
	if (count == 0)
	{
		return 0;
	}
	else if (count == 1)
	{
		return 1;
	}
	else if (count > 1)
	{
		int temp{ 0 };
		int first{ 0 };
		int second{ 1 };
		for (int index = 1; index < count; ++index)
		{
				temp = first + second;
				first = second;
				second = temp;
		}
		return temp;
	}
}

int main()
{
	std::cout << "This is fibonacci.\n";
	std::cout << "Enter the length (in int): ";
	int length{ 0 };
	std::cin >> length;
	std::cout << "Fibonacci series: ";
	for (int index = 0; index < length; ++index)
	{
		std::cout << ficonacci(index) << " ";
	}

	//To keep the cmd open
	while (true);
    return 0;
}

