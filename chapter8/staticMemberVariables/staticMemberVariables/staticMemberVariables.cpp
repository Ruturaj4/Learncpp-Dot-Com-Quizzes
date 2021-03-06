// staticMemberVariables.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class Something
{
	static int s_idGenerator;
	int m_id;

public:
	Something()
	{
		m_id = s_idGenerator++;
	}
	int getId() const
	{
		return m_id;
	}
};

int	Something::s_idGenerator{ 1 };

int main()
{
	Something one;
	Something two;
	Something three;

	std::cout << "First id: " << one.getId() << '\n';
	std::cout << "Second id: " << two.getId() << '\n';
	std::cout << "Third id: " << three.getId() << '\n';

	//To keep the cmd open
	while (true);
	return 0;
}
