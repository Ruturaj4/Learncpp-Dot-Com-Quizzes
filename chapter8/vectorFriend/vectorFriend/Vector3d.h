#pragma once
#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "Point3d.h"

class Vector3d
{
	double m_x, m_y, m_z;
public:
	Vector3d(double x, double y, double z) :m_x(x), m_y(y), m_z(z)
	{

	}
	void print();
	friend void Point3d::moveByVector(const Vector3d &v);
};

#endif // !VECTOR3D.H