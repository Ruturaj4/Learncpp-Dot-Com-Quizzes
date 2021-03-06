// arrayPointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	const int arrayLength{ 7 };
	char array[arrayLength]{ "Mollie" };
	int numVowels{ 0 };
	for (char *ptr = array; ptr < (array + arrayLength); ptr++)
	{
		switch (*ptr)
		{
		case 'A':
		case 'a':
		case 'E':
		case 'e':
		case 'I':
		case 'i':
		case 'O':
		case 'o':
		case 'U':
		case 'u':
			++numVowels;
		}
	}
	std::cout << "Total number of vowels are: " << numVowels << "\n";

	//To keep the cmd open
	while (true);
    return 0;
}

