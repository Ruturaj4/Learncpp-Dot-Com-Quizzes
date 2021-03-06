// recursive_fibonacci.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int fibonacci(int index)
{
	if (index == 0)
		return 0;
	else if (index == 1)
		return 1;
	else if (index > 1)
		return fibonacci(index - 1) + fibonacci(index - 2);
}

int main()
{
	std::cout << "Welcome to The Fibonacci\n";
	std::cout << "Enter a sequence length(or count): ";
	int count{ 0 };
	std::cin >> count;
	std::cout << "The Fibonacci series till " << count << ": ";
	for (int index = 0; index < count; index++)
	{
		std::cout << fibonacci(index) << " ";
	}

	//To keep the cmd open
	while (true);
    return 0;
}