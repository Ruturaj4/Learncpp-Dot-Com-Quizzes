// classIntro.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Introduction to classes and object oriented programming

#include "pch.h"
#include <iostream>

class IntPair {
	// Two member variables to hold the integers
public:
	int m_intOne;
	int m_intTwo;

	// Member function set
	void set(int valueOne, int valueTwo)
	{
		m_intOne = valueOne;
		m_intTwo = valueTwo;
	}

	// Member function print
	void print()
	{
		std::cout << "Two integers are: " << m_intOne << ", " << m_intTwo << '\n';
	}
};

int main()
{
	IntPair p1;
	p1.set(1, 1); // set p1 values to (1, 1)
	IntPair p2{ 2, 2 }; // initialize p2 values to (2, 2)

	p1.print();
	p2.print();

	// To keep the cmd open
	while (true);
	return 0;
}