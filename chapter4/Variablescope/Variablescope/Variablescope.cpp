// Variablescope.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	//create two variables with the scope of main
	int intOne, intTwo;
	std::cout << "Enter an integer: ";
	std::cin >> intOne;
	std::cout << "Enter a larger integer: ";
	std::cin >> intTwo;
	if (intOne > intTwo)
	{
		//Creating a variable to store a temporary value of intOne, who's scope is limited to the 'if' block
		int temp;
		temp = intOne;
		intOne = intTwo;
		intTwo = temp;
		std::cout << "Swapping the values\n";
	}//temp is destroyed here
	std::cout << "The smaller value is " << intOne << std::endl;
	std::cout << "The larger value is " << intTwo << std::endl;
	//To keep the cmd open
	int x;
	std::cin >> x;
    return 0;
}//intOne and intTwo are destroyed here