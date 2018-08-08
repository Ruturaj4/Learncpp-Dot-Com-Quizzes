#include"stdafx.h"
#include<iostream>

double getInitialHeight()
{
	std::cout << "Please enter the height of the tower is meters: ";
	double heightOfTower;
	std::cin >> heightOfTower;
	std::cout << "You entered: " << heightOfTower << "\n";
	return heightOfTower;
}