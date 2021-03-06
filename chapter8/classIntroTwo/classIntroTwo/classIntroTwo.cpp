// classIntroTwo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class Point3d
{
	double m_x, m_y, m_z;
public:
	void setValues(double valueOne, double valuetwo, double valueThree)
	{
		m_x = valueOne;
		m_y = valuetwo;
		m_z = valueThree;
	}
	void print()
	{
		std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">\n";
	}
	bool isEqual(Point3d &point)
	{
		return (m_x == point.m_x) && (m_y == point.m_y) && (m_z == point.m_z);
	}
};

int main()
{
	Point3d point1;
	point1.setValues(1.0, 2.0, 3.0);

	Point3d point2;
	point2.setValues(1.0, 2.0, 3.0);

	if (point1.isEqual(point2))
		std::cout << "point1 and point2 are equal\n";
	else
		std::cout << "point1 and point2 are not equal\n";

	Point3d point3;
	point3.setValues(3.0, 4.0, 5.0);

	if (point1.isEqual(point3))
		std::cout << "point1 and point3 are equal\n";
	else
		std::cout << "point1 and point3 are not equal\n";
    //To keep the cmd open
	while (true);
	return 0;
}