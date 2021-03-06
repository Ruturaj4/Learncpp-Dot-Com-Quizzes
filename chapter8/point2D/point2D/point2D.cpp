// point2D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
//Header for sqrt
#include <cmath>

class Point2D
{
	//Values initialized by default
	double m_x{ 0 };
	double m_y{ 0 };
public:
	Point2D(double m = 0.0, double n = 0.0) : m_x(m), m_y(n)
	{

	}
	void getPoint2D()
	{
		std::cout << "m_x is: " << m_x << ", m_y is: " << m_y << '\n';
	}

	int distanceTo(const Point2D &objOne, const Point2D &objTwo) const;
};

int Point2D::distanceTo(const Point2D &objOne, const Point2D &objTwo) const
{
	return sqrt((objOne.m_x - objTwo.m_x)*(objOne.m_x - objTwo.m_x) + (objOne.m_y - objTwo.m_y)*(objOne.m_y - objTwo.m_y));
}

int main()
{
	Point2D first;
	Point2D second(3.0, 4.0);
	first.getPoint2D();
	second.getPoint2D();
	std::cout << "Distance between two points: " << first.distanceTo(first, second) << '\n';

	//To keep the cmd open
	while (true);
}