// multiple_files.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//#include "new.cpp" #Don't include the file like this
#include "add.h"

int main()
{
	int x;
	std::cout << "Some of the three numbers is: " << add(2, 3, 4) << std::endl;
	std::cin >> x;
    return 0;
}