//This function calculates and prints the height of the ball

#include "stdafx.h"
#include <iostream>
#include "constants.h"

double calculateHeight(double initialHeight, int secondsPassed)
{
	double distanceFallen = (myConstants::gravity * secondsPassed * secondsPassed) / 2;
	double currentHeight = initialHeight - distanceFallen;
	return currentHeight;
}

void printHeight(double height, int secondsPassed)
{
	if (height > 0.0)
		std::cout << "At " << secondsPassed << " ball is at the height " << height << "m.\n";
	else
		std::cout << "At " << secondsPassed << ", the ball reached the ground\n";
}

void calculateAndPrintHeight(double initialHeight, int secondsPassed)
{
	double height = calculateHeight(initialHeight, secondsPassed);
	printHeight(height, secondsPassed);
}