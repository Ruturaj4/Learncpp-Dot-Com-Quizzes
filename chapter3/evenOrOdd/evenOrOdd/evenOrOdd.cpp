// evenOrOdd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int isEven(int num)
{
	return (num % 2) == 0;
}

int main()
{
	std::cout << "This program finds if the number is true or false" << std::endl;
	std::cout << "Enter an integer:" << std::endl;
	int num;
	std::cin >> num;
	if (isEven(num))
		std::cout << num << " is an even number" << std::endl;
	else
		std::cout << num << " is an odd number" << std::endl;

	//To keep the cmd open
	int x;
	std::cin >> x;
    return 0;
}