// inoutOperatorOverloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class Fraction {
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator=0, int denomenator=1):m_numerator(numerator), m_denominator(denomenator)
	{
		reduce();
	}
	static int gcd(int a, int b)
	{
		return b == 0 ? a : gcd(b, a % b);
	}
	void reduce()
	{
		int gcd = Fraction::gcd(m_numerator, m_denominator);
		m_numerator /= gcd;
		m_denominator /= gcd;
	}
	void print()
	{
		std::cout << m_numerator << "/" << m_denominator << "\n";
	}

	friend Fraction operator*(const Fraction &f1, const Fraction &f2);
	friend Fraction operator*(const Fraction &f1, int value);
	friend Fraction operator*(int value, const Fraction &f1);
	friend std::ostream& operator<<(std::ostream &out, const Fraction &fraction);
	friend std::istream& operator>>(std::istream &in, Fraction &fraction);
};

std::ostream& operator<<(std::ostream &out, const Fraction &fraction)
{
	out << fraction.m_numerator << "/" << fraction.m_denominator;
		return out;
}

std::istream& operator>>(std::istream &in, Fraction &fraction)
{
	char c;
	in >> fraction.m_numerator;
	in >> c;
	in >> fraction.m_denominator;
	// Since we overwrite the existing f1, we need to reduce again
	fraction.reduce();
	return in;
}

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
	return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}

Fraction operator*(const Fraction &f1, int value)
{
	return Fraction(f1.m_numerator * value, f1.m_denominator);
}

Fraction operator*(int value, const Fraction &f1)
{
	return Fraction(f1.m_numerator * value, f1.m_denominator);
}

int main()
{
	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';

    //to keep the cmd open
	while (true);
	return 0;
}