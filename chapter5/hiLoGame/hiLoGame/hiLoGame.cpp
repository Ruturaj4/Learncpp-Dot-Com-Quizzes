// hiLoGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>

int handleInput()
{
	while (true)
	{
		int number;
		std::cin >> number;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Please guess a number between 1 and 100!\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return number;
		}
	}
}

int getRandomNumber(int min, int max)
{
	static const double fraction{1.0/(RAND_MAX+1.0)};
	return min + static_cast<int>((max - min + 1)*(std::rand() * fraction));
}

void singleGame(int myNumber)
{
	int tries{ 1 };
	while (tries <= 7)
	{
		int number;
		number = handleInput();
		std::cout << "Guess #" << tries << ": " << number << "\n";
		if (number == myNumber)
		{
			std::cout << "Correct! You win!\n";
			return;
		}
		else if (number > myNumber)
			std::cout << "Number is too high\n";
		else if (number < myNumber)
			std::cout << "Number is too low\n";
		tries++;
	}
	std::cout << "Sorry, you loose! But, keep trying again! The correct number was: " << myNumber << "\n";
}

int main()
{
	while (true)
	{
		std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";
		std::srand(time(0));
		getRandomNumber(1, 100);
		int myNumber = getRandomNumber(1, 100);
		singleGame(myNumber);
		while (true)
		{
			std::cout << "Would you like to play again? (y/n): ";
			char play;
			std::cin >> play;
			std::cin.ignore(32767, '\n');
			if (play == 'y')
				break;
			else if (play == 'n')
				return 0;
			else
				std::cout << "Please enter only y or n.\n";
		}
	}
	std::cout << "Thank you for playing.\n";
	//To keep the cmd open
	while (true);
    return 0;
}