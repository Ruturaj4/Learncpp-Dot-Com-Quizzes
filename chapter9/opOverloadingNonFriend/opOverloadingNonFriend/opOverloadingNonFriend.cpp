// opOverloadingNonFriend.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class Cents
{
	int m_cents;
public:
	Cents(int cents)
	{
		m_cents = cents;
	}
	int getCents() const
	{
		return m_cents;
	}
};

Cents operator+(const Cents &centsOne, const Cents &centsTwo)
{
	return Cents(centsOne.getCents() + centsTwo.getCents());
}

int main()
{
	Cents centsOne{ 6 };
	Cents centsTwo{ 7 };
	Cents total{ centsOne + centsTwo };
	std::cout << "The total is: " << total.getCents();
    //To keep the cmd open
	while (true);
	return 0;
}