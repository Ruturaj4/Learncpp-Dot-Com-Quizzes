// calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "calculate.h"

int main()
{
	int firstNumber, mathOperator, secondNumber, result;
	std::cout << "Welcome to my calculator: " << std::endl;
	firstNumber = numberOne();
	mathOperator = getOperator();
	secondNumber = numberTwo();

	result = calculateTheResult(firstNumber, mathOperator, secondNumber);
	printOutput(result);

	//To dispaly the result without closing the console abruptly
	std::cin >> result;

    return 0;
}
