// cStylePointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

void printCStyle(char *hello)
{
	int index{ 0 };
	while (hello[index] != '\0')
	{
		std::cout << hello[index];
		++index;
	}
}

int main()
{
	char hello[] = "Hello, world!";
	printCStyle(hello);
	//To keep the cmd open
	while (true);
    return 0;
}

