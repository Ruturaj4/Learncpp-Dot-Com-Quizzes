#include "stdafx.h"
#include <iostream>

int numberOne()
{
	int num;
	std::cout << "Enter the first number: ";
	std::cin >> num;
	return num;
}

int getOperator()
{
	int op;
	std::cout << "Now enter the operator (0-'+', 1-'-', 2-'*', 3-'/'): ";
	std::cin >> op;
	return op;
}

int numberTwo()
{
	int num;
	std::cout << "Enter the second number: ";
	std::cin >> num;
	return num;
}

int calculateTheResult(int firstNumber, int mathOperator, int secondNumber)
{
	int result;

	if (mathOperator == 0)
		result = firstNumber + secondNumber;
	else if (mathOperator == 1)
		result = firstNumber - secondNumber;
	else if (mathOperator == 2)
		result = firstNumber * secondNumber;
	else if (mathOperator == 3)
		result = firstNumber / secondNumber;
	else
		//we will do addition for an invalid operator
		result = firstNumber + secondNumber;
	return result;

}

void printOutput(int ans)
{
	std::cout << "ANS: " << ans << std::endl;
}