// commandLineArgs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//You need to pass the commandline arguments to the program
int main(int argc, char *argv[])
{
	std::cout << "There are " << argc << " elements.\n";

	//Loop through each argument and print its number and value
	for (int index = 0; index < argc; ++index)
	{
		std::cout << argc << " " << argv[index] << "\n";
	}

	//To keep the cmd open
	while (true);
    return 0;
}

