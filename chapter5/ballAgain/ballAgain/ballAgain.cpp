// ballAgain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

double getInitialHeight();
void calculateAndPrintHeight(double initialHeight, int secondsPassed);
double calculateHeight(double initialHeight, int secondsPassed);

int main()
{
	double initialHeight = getInitialHeight();
	int seconds{0};
	double height;

	do
	{
		height = calculateHeight(initialHeight, seconds);
		calculateAndPrintHeight(initialHeight, seconds);
		++seconds;
	} while (height > 0.0);

	//To keep the cmd open
	while (1)
	{ }
    return 0;
}

