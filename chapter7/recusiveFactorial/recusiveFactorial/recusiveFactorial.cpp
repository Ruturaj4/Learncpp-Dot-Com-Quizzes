// recusiveFactorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int factorial(int number)
{
	if (number <= 0)
		return 1;
	return factorial(number - 1) * number;
}

int main()
{
	std::cout << "This is a factorial program\n";
	std::cout << "Enter an integer, to calculate its factorial.\n";
	int number;
	std::cin >> number;
	std::cout << "The factorial of first " << number << " numbers is: ";
	for (int index = 1; index <= number; index++)
	{
		std::cout << factorial(index) << " ";
	}

	//To keep the cmd open
	while (true);
    return 0;
}