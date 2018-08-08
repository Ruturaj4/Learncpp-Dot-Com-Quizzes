// playingWIthStrings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

int main()
{
	using std::cout;
	using std::cin;
	cout << "Please enter your full name: ";
	std::string fullName;
	std::getline(cin, fullName);
	cout << "Please enter your age: ";
	int age{0};
	cin >> age;
	int letters = fullName.length();
	double agePerLetter = static_cast<double> (age) / letters;
	cout << "You have lived " << agePerLetter << " years for each letter in your name\n";

	//To keep the cmd open
	int x;
	cin >> x;
    return 0;
}

