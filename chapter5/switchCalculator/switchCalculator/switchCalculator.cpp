// switchCalculator.cpp : Defines the entry point for the console application.
// Simple calculator using swtich statement

#include "stdafx.h"
#include <iostream>

int calculate(int intOne, int intTwo, char op)
{
	switch (op)
	{
	case '+':
		return intOne + intTwo;
	case '-':
		return intOne - intTwo;
	case '*':
		return intOne * intTwo;
	case '/':
		return intOne / intTwo;
	case '%':
		return intOne % intTwo;
	default:
		std::cout << "There is an error!\n";
		return 0;
	}
}

int main()
{
	std::cout << "This is a simple calculator using switch statements." << std::endl;
	std::cout << "Please enter an integer: ";
	int intOne;
	std::cin >> intOne;
	std::cout << "Please enter another integer: ";
	int intTwo;
	std::cin >> intTwo;
	std::cout << "Now enter an operator (+,-,*,/,%): ";
	//op is the operator
	char op;
	std::cin >> op;
	std::cout << "Your answer is: " << calculate(intOne, intTwo, op) << std::endl;
	//To keep the cmd open
	int x;
	std::cin >> x;
    return 0;
}

