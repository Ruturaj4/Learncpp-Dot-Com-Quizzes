// operatorOverloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class Fraction
{
	int m_numerator;
	int m_denomenator;
public:
	Fraction(int num = 1, int deno = 1)
	{
		m_numerator = num;
		m_denomenator = deno;
		{
			reduce();
		}
	}
	void print()
	{
		std::cout << m_numerator << "/" << m_denomenator << '\n';
	}
	int gcd(int a, int b) {
		return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
	}
	void reduce()
	{
		int temp = gcd(m_numerator, m_denomenator);
		m_numerator = m_numerator / temp;
		m_denomenator = m_denomenator / temp;

	}
	friend Fraction operator*(const Fraction &operatorOne, const Fraction &operatorTwo);
	friend Fraction operator*(const Fraction &operatorOne, const int &num);
	friend Fraction operator*(const int &num, const Fraction &operatorOne);
};

Fraction operator*(const Fraction &operatorOne, const Fraction &operatorTwo)
{
	int numerator = operatorOne.m_numerator * operatorTwo.m_numerator;
	int denominator = operatorOne.m_denomenator * operatorTwo.m_denomenator;
	return Fraction(numerator, denominator);
}

Fraction operator*(const Fraction &operatorOne, const int &num)
{
	int numerator = operatorOne.m_numerator * num;
	return Fraction(numerator, operatorOne.m_denomenator);
}

Fraction operator*(const int &num, const Fraction &operatorOne)
{
	return operatorOne * num;
}

int main()
{
	Fraction f1(2, 5);
	f1.print();

	Fraction f2(3, 8);
	f2.print();

	Fraction f3 = f1 * f2;
	f3.print();

	Fraction f4 = f1 * 2;
	f4.print();

	Fraction f5 = 2 * f2;
	f5.print();

	Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
	f6.print();

    // To keep the cmd open
	while (true);
	return 0;
}