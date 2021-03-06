// classConstructor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

class Ball
{
	std::string m_color{ "Black" };
	double m_radius{ 10.0 };
public:
	Ball(const std::string &color = "Black", double radius = 10.0)
	{
		m_color = color;
		m_radius = radius;
	}
	Ball(double radius)
	{
		m_radius = radius;
	}
	void print()
	{
		std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
	}
};

int main()
{
	Ball def;
	def.print();

	//Direct initialization
	Ball blue("Blue");
	blue.print();

	//Copy initialization - Don't do it!
	Ball twenty = Ball{20.0};
	twenty.print();

	//Uniform initialization
	Ball blueTwenty{"Blue", 20.0};
	blueTwenty.print();

	//To keep the cmd open
	while (true);
	return 0;
}