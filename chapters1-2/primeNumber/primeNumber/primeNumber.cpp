// primeNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int isPrime(int x)
{
	if ((x == 2) || (x == 3) || (x == 5) || (x == 7))
		return 1;
	else
		return 0;
}

int main()
{
	int x;
	std::cout << "Enter a number between 1 to 10" << std::endl;
	std::cin >> x;
	if (isPrime(x))
		std::cout << "Your number is prime" << std::endl;
	else
		std::cout << "Your number is not a prime number" << std::endl;
	//To keep the cmd open we will add cin
	std::cin >> x;
    return 0;
}

