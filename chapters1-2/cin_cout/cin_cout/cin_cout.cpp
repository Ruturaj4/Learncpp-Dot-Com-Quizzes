// cin_cout.cpp : Working with cin and cout

#include "stdafx.h"
#include <iostream>

int main()
{
	int x = 0;
	std::cout << "Enter a number:"<<std::endl;
	std::cin >> x;
	std::cout << "You entered: " << x << std::endl;
	std::cin >> x;
    return 0;
}

