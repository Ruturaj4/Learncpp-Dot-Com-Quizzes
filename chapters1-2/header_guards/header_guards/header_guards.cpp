// header_guards.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "square.h"

int main()
{
	int x;
	std::cout << "If the square has " << squareSide() << " sides, ";
	std::cout << "The square has a perimeter of " << squarePerimeter(5)<<std::endl;
	std::cin >> x;
    return 0;
}

