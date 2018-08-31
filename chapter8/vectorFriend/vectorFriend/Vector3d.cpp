#include "pch.h"
#include <iostream>
#include "Vector3d.h"

void Vector3d::print()
{
	std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}