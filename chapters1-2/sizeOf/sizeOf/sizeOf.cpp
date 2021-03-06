// sizeOf.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	std::cout << "bool:\t\t" << sizeof(bool) << " byte/s" << std::endl;
	std::cout << "char:\t\t" << sizeof(char) << " byte/s" << std::endl;
	std::cout << "wchar_t:\t\t" << sizeof(wchar_t) << " byte/s" << std::endl;
	std::cout << "char16_t:\t\t" << sizeof(char16_t) << " byte/s" << std::endl;
	std::cout << "char32_t:\t\t" << sizeof(char32_t) << " byte/s" << std::endl;
	std::cout << "short:\t\t" << sizeof(short) << " byte/s" << std::endl;
	std::cout << "int:\t\t" << sizeof(int) << " byte/s" << std::endl;
	std::cout << "long:\t\t" << sizeof(long) << " byte/s" << std::endl;
	std::cout << "long long:\t\t" << sizeof(long long) << " byte/s" << std::endl;
	std::cout << "float:\t\t" << sizeof(float) << " byte/s" << std::endl;
	std::cout << "double:\t\t" << sizeof(double) << " byte/s" << std::endl;
	std::cout << "long double:\t\t" << sizeof(long double) << " byte/s" << std::endl;
	//fixed interger type
	std::cout << "int16_t:\t\t" << sizeof(int16_t) << " byte/s" << std::endl;
	//When you want more performance, use fast int
	std::cout << "int_fast16_t:\t\t" << sizeof(int_fast16_t) << " byte/s" << std::endl;
	//When you want specific memory, use least int
	std::cout << "int_least16_t:\t\t" << sizeof(int_least16_t) << " byte/s" << std::endl;

	//To keep the cmd window open
	int x;
	std::cin >> x;

    return 0;
}

