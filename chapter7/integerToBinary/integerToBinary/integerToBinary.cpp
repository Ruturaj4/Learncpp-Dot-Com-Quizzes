// integerToBinary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void intToBin(unsigned int posInt)
{
	if (posInt > 0)
	{
		intToBin(posInt / 2);
		if ((posInt % 2) == 0)
		{
			std::cout << 0 << " ";
		}
		else if ((posInt % 2) == 1)
		{
			std::cout << 1 << " ";
		}
	}
	
	//This can be done in one single line - std::cout<<posInt%2; as given on learncpp.com
}

int main()
{
	std::cout << "Please enter an integer: ";
	int posInt{ 0 };
	std::cin >> posInt;
	std::cout << "Binary representation: ";
	intToBin(posInt);

	//To keep the cmd open
	while (true);
    return 0;
}

