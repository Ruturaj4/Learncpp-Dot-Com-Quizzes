// decimal_binary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void decToBinary(int dec_num)
{
	//Assume the largest power of 2 is 128
	int max_value = 128;
	while ((dec_num > 0) || (max_value >= 1))
	{
		if (dec_num >= max_value)
		{
			dec_num = dec_num - max_value;
			std::cout << 1;
		}
		else
		{
			std::cout << 0;
		}
		max_value = max_value / 2;
	}

}

int main()
{
	std::cout << "Enter the decimal number: ";
	int dec_num;
	std::cin >> dec_num;
	decToBinary(dec_num);
	//To keep the cmd open
	int x;
	std::cin >> x;
    return 0;
}

