// functions.cpp : Let's play with the funcions.
//

#include "stdafx.h"
#include <iostream>


int add(int a, int b) {
	return a + b;
}

int mul(int a, int b) {
	return a * b;
}

int main() {

	int x, y;

	std::cout << "Enter the vlues of x and y" << std::endl;
	std::cin >> x >> y;
	std::cout << "The vlue is: " << add(x, mul(x, y)) << std::endl;
	std::cin >> x;
	return 0;
}