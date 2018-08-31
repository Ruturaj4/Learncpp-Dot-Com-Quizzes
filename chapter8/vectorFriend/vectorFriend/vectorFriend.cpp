// vectorFriend.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Point3d.h"
#include "Vector3d.h"

int main()
{
    Point3d p(1.0, 2.0, 3.0);
	Vector3d v(2.0, 2.0, -3.0);
	p.print();
	v.print();
	p.moveByVector(v);
	p.print();
	//To keep the cmd open
	while (true);
	return 0;
}