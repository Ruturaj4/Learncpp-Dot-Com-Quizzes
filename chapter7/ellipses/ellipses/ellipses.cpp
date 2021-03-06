// ellipses.cpp : Defines the entry point for the console application.
// In this code, we will use a decorative string method.
// This program is reffred from learncpp.com

#include "stdafx.h"
#include<string>
#include <iostream>
//For ellipses we need cstdarg
#include <cstdarg>

double findAverage(std::string decoder, ...)
{
	//To calculate the sum
	double sum{ 0 };

	//We will access ellipses through va_list
	va_list list;

	//we will 'start' (initialize the va_list) the ellipses, using va_start
	va_start(list, decoder);

	int count{ 0 };
	while (1)
	{
		char codetype = decoder[count];
		switch (codetype)
		{
		default:
		case '\0':
			va_end(list);
			return sum / count;
			break;
		case 'i':
			sum += va_arg(list, int);
			++count;
			break;
		case 'd':
			sum += va_arg(list, double);
			++count;
			break;
		}
	}

}

int main()
{
	std::cout << findAverage("iiiii", 1, 2, 3, 4, 5) << "\n";
	std::cout << findAverage("iiiiii", 1, 2, 3, 4, 5, 6) << "\n";
	std::cout << findAverage("iiddi", 1, 2, 3.5, 4.5, 5) << "\n";
	
	//To keep the cmd open
	while (true);
    return 0;
}

