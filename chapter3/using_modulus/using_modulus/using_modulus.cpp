// using_modulus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	std::cout << "In this example, we will print the numbers from 1 to 100, 20 each line."<<std::endl;

	int num = 1;
	while (num < 101)
	{
		std::cout << num << " ";
		if (num % 20 == 0)
			std::cout << std::endl;
		num++;
	}
	//To keep the cmd open
	int x;
	std::cin >> x;
    return 0;
}

