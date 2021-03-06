// forEach.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

int main()
{
	const int length{ 8 };
	std::string array[length] = { "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };
	std::cout << "Please enter a name: ";
	std::string name;
	std::cin >> name;
	bool found{ false };
	for (auto &ref : array)
	{
		if (name == ref)
		{
			found = true;
		}
	}
	if (found)
		std::cout << name << " was found.\n";
	else
		std::cout << name << " was not found";

	//To keep the cmd open
	while (true);
    return 0;
}

