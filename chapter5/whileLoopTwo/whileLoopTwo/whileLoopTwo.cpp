// whileLoopTwo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	int outer{ 1 };
	while (outer <= 5)
	{
		int inner = 6 - outer;
		while (inner >= 1)
		{
			std::cout << inner-- << " ";
		}
		std::cout << "\n";
		++outer;
	}
	//To keep the cmd open
	int x;
	std::cin >> x;
    return 0;
}

