// ballSimulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "constants.h"

void heightOfTheBall(int x, float heightOfTower)
{
	float height;
	height = (myConstants::gravity * (x * x)) / 2;
	height = heightOfTower - height;
	if (height > 0.0)
		std::cout << "At " << x << " seconds, the ball is at height: " << height << " meter/s\n";
	else
		std::cout << "At " << x << " seconds, the ball is on the ground.";
}

int main()
{
	double heightOfTower;
	std::cout << "Please enter height of tower in meter/s" << std::endl;
	std::cin >> heightOfTower;
	heightOfTheBall(0, heightOfTower);
	heightOfTheBall(1, heightOfTower);
	heightOfTheBall(2, heightOfTower);
	heightOfTheBall(3, heightOfTower);
	heightOfTheBall(4, heightOfTower);
	heightOfTheBall(5, heightOfTower);
	//To keep the cmd window open
	int x;
	std::cin >> x;
    return 0;
}

