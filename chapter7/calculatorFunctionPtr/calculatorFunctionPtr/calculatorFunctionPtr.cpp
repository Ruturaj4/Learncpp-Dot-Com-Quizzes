// calculatorFunctionPtr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//create a function pointer
typedef int(*arithmeticFcn)(int, int);
struct arithmeticStruct;

int getInteger()
{
	std::cout << "Please enter an integer: ";
	int userInt;
	std::cin >> userInt;
	std::cin.ignore(32767, '\n');
	return userInt;
}

int getOperator()
{
	char mathOperator;
	do
	{
		std::cout << "Now enter the operator (+, -, *, /): ";
		std::cin >> mathOperator;
		std::cin.ignore(32767, '\n');
	} while ((mathOperator != '+') && (mathOperator != '-') && (mathOperator != '/') && (mathOperator != '*'));
	return mathOperator;
}

int add(int intOne, int intTwo)
{
	return intOne + intTwo;
}

int subtract(int intOne, int intTwo)
{
	return intOne - intTwo;
}

int multiply(int intOne, int intTwo)
{
	return intOne * intTwo;
}

int divide(int intOne, int intTwo)
{
	return intOne / intTwo;
}

struct arithmeticStruct
{
	char mathOperator;
	arithmeticFcn functionPtr;
};

//create a structure array
static const arithmeticStruct arithmeticArray[]{ { '+', add },{ '-', subtract },{ '*', multiply } ,{ '/', divide } };

arithmeticFcn getArithmeticFunction(char op)
{
	for (const auto index : arithmeticArray)
	{
		if (index.mathOperator == op)
		{
			return index.functionPtr;
		}
	}
	return add;
}

int main()
{
	std::cout << "Welcome to the calculator.\n";
	int intOne = getInteger();
	int mathOperator = getOperator();
	int intTwo = getInteger();
	arithmeticFcn fun{ getArithmeticFunction(mathOperator) };
	std::cout << "Result: " << fun(intOne, intTwo) << "\n";

	//To keep the cmd open
	while (true);
    return 0;
}

