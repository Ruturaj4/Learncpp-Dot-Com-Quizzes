// refSwap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//Passing the values by reference
void swapValues(int &firstInteger, int &secondInteger)
{
	int temp;
	temp = firstInteger;
	firstInteger = secondInteger;
	secondInteger = temp;
}

int main()
{
	std::cout << "Please enter two integers: \n";
	int firstInteger;
	int secondInteger;
	std::cin >> firstInteger;
	std::cin >> secondInteger;
	std::cout << "Before swapping: first is " << firstInteger << " and second is " << secondInteger << "\n";
	swapValues(firstInteger, secondInteger);
	std::cout << "After swapping: first is " << firstInteger << " and second is " << secondInteger;
	//To keep the cmd open
	while (true);
    return 0;
}