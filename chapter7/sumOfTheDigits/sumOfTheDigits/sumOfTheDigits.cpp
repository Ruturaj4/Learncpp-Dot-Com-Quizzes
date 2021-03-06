// sumOfTheDigits.cpp : Defines the entry point for the console application.
// Write a recursive function that takes an integer as input and returns the sum of each individual digit in the integer (e.g. 357 = 3 + 5 + 7 = 15).
//Print the answer for input 93427 (which is 25). Assume the input values are positive.

#include "stdafx.h"
#include <iostream>

int sumOfDigits(int givenNumber)
{
	int sum{ 0 };
	if (givenNumber <= 0)
		return 0;
	sum += givenNumber % 10;
	return sumOfDigits(givenNumber / 10) + sum;
}

int main()
{
	//Let the number be 93427, as given in the example
	int givenNumber{ 93427 };
	int sum{ sumOfDigits(givenNumber) };
	std::cout << sum;

	//To keep the cmd open
	while (true);
    return 0;
}