// chapter_one_quiz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "io.h"

int main()
{
	int x, y, ans;
	std::cout << "Enter two integers"<<std::endl;
	x = readNumbers();
	y = readNumbers();
	ans = x + y;
	writeAnswer(ans);
	//To keep cmd open, using a cin function
	std::cin >> x;
    return 0;
}

