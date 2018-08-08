#include "stdafx.h"
#include <iostream>

int readNumbers()
{
	int x;
	std::cin >> x;
	return x;
}

void writeAnswer(int ans)
{
	std::cout << "The answer is " << ans << std::endl;
}