// arrayOne.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
namespace Animal
{
	enum Animal
	{
		CHICKEN,
		DOG,
		CAT,
		ELEPHANT,
		DUCK,
		SNAKE,
		MAX_ANIMALS,
	};
}

int main()
{
	int legs[Animal::MAX_ANIMALS]{ 2, 4, 4, 4, 2 };
	std::cout << "The elephant has " << legs[Animal::ELEPHANT] << " legs.\n";

	//To keep the cmd open
	while (true);

    return 0;
}

