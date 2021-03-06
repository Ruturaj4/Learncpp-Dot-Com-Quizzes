// structFraction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

struct Fraction
{
	int numerator;
	int denomenator;
};

void multiply(Fraction f1, Fraction f2)
{
	double ans = (static_cast<double>(f1.numerator) * f2.numerator) / (f1.denomenator * f2.denomenator);
	std::cout << ans;
}

int main()
{
	Fraction f1;
	std::cout << "Enter a numerator of first fraction: ";
	std::cin >> f1.numerator;
	std::cout << "Now enter a denomenator of first fraction: ";
	std::cin >> f1.denomenator;

	Fraction f2;
	std::cout << "Enter a numerator of second fraction: ";
	std::cin >> f2.numerator;
	std::cout << "Now enter a denomenator of second fraction: ";
	std::cin >> f2.denomenator;
	multiply(f1, f2);

	//To keep the cmd open
	int x;
	std::cin >> x;

    return 0;
}

