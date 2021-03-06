// destructorClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class HelloWorld
{
	char *m_data;
public:
	HelloWorld()
	{
		m_data = new char[14];
		const char *init{ "Hello World!" };
		for (int index = 0; index < 14; index++)
		{
			m_data[index] = init[index];
		}
	}

	~HelloWorld()
	{
		delete[] m_data;
	}

	void print() const
	{
		std::cout << m_data << '\n';
	}
};

int main()
{
	HelloWorld hello;
	hello.print();

	//To keep the cmd open
	while (true);
}