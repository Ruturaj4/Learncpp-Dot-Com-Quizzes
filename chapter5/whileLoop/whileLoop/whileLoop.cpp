// whileLoop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	//Intialize a with the value of 97 (which is an ascii value of a)
	char myChar{'a'};
	std::cout << "Letter\tAscii value\n";
	while (myChar < 'z')
	{
		std::cout << myChar << "\t" << static_cast<int>(myChar) << "\n";
		++myChar;
	}

	//To keep the cmd open
	int x;
	std::cin >> x;
    return 0;
}

