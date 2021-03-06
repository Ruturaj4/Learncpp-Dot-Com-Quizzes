// simpleStackUsingClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cassert>

class Stack
{
	// Let's say our stack is of the fixed length 10
	int m_array[10];
	// A variable to manage the length of the stack
	int m_lengthOfTheStack;

public:
	// Reset the stack
	void reset()
	{
		// Sets length of the stack to zero
		m_lengthOfTheStack = 0;
		// Sets all the other elements of the stack to zero
		for (int index = 0; index < m_lengthOfTheStack; ++index)
		{
			m_array[index] = 0;
		}
	}
	// Push a value pn the stack
	void push(int value)
	{
		m_array[m_lengthOfTheStack] = value;
		++m_lengthOfTheStack;
	}
	// Pop a value from the stack
	void pop()
	{
		assert(m_lengthOfTheStack > 0 && "Can not pop empty stack");
		m_array[m_lengthOfTheStack] = 0;
		--m_lengthOfTheStack;
	}
	// Print all the values in the stack
	void print()
	{
		std::cout << "( ";
		for (int index = 0; index < m_lengthOfTheStack; index++)
		{
			std::cout << m_array[index] << " ";
		}
		std::cout << ")\n";
	}
};

int main()
{
	Stack stack;
	stack.reset();

	stack.print();
	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

    //To keep the cmd open
	while (true);
	return 0;
}