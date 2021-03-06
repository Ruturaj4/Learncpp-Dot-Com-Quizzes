// cardGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>

enum class CardRanks
{
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE,
	TOTAL_CARDS,
};

enum class CardSuits
{
	CLUBES,
	DIAMONDS,
	HEARTS,
	SPADES,
	TOTAL_SUITS,
};

struct Card
{
	CardRanks rank;
	CardSuits suit;
};

void printCard(const Card &card)
{
	switch (card.rank)
	{
	case CardRanks::TWO:
		std::cout << "2";
		break;
	case CardRanks::THREE:
		std::cout << "3";
		break;
	case CardRanks::FOUR:
		std::cout << "4";
		break;
	case CardRanks::FIVE:
		std::cout << "5";
		break;
	case CardRanks::SIX:
		std::cout << "6";
		break;
	case CardRanks::SEVEN:
		std::cout << "7";
		break;
	case CardRanks::EIGHT:
		std::cout << "8";
		break;
	case CardRanks::NINE:
		std::cout << "9";
		break;
	case CardRanks::TEN:
		std::cout << "10";
		break;
	case CardRanks::JACK:
		std::cout << "J";
		break;
	case CardRanks::QUEEN:
		std::cout << "Q";
		break;
	case CardRanks::KING:
		std::cout << "K";
		break;
	case CardRanks::ACE:
		std::cout << "A";
		break;
	default:
		std::cout << "?";
		break;
	}
	switch (card.suit)
	{
	case CardSuits::CLUBES:
		std::cout << "C";
		break;
	case CardSuits::DIAMONDS:
		std::cout << "D";
		break;
	case CardSuits::HEARTS:
		std::cout << "H";
		break;
	case CardSuits::SPADES:
		std::cout << "S";
		break;
	default:
		std::cout << "?";
		break;
	}
}

void printDeck(std::array<Card, 52> &myArray)
{
	for (const auto &index : myArray)
	{
		printCard(index);
		std::cout << " ";
	}
	std::cout << "\n";
}

void swapCards(Card &one, Card &two)
{
	Card temp;
	temp = one;
	one = two;
	two = temp;
}

int randomNumberGenerator(int min, int max)
{
	//Calling rand once more, before rand to keep it random (visual studio)
	std::rand();
	static const double fraction = 1.0 / (RAND_MAX + 1.0);
	return min + static_cast<int>((max - min + 1) * (std::rand()*fraction));
}

void shuffleDeck(std::array<Card, 52> &myArray)
{
	int randomNumber{ 1 };
	for (int index = 0; index < 52; index++)
	{
		randomNumber = randomNumberGenerator(0, 51);
		swapCards(myArray[index], myArray[randomNumber]);
	}
}

int getCardValue(const Card &card)
{
	int cardValue{ 0 };
	switch (card.rank)
	{
	case CardRanks::TWO: return 2;
	case CardRanks::THREE: return 3;
	case CardRanks::FOUR: return 4;
	case CardRanks::FIVE: return 5;
	case CardRanks::SIX: return 6;
	case CardRanks::SEVEN: return 7;
	case CardRanks::EIGHT: return 8;
	case CardRanks::NINE: return 9;
	case CardRanks::TEN: return 10;
	case CardRanks::JACK: return 10;
	case CardRanks::QUEEN: return 2;
	case CardRanks::KING: return 2;
	case CardRanks::ACE: return 2;
	}
	return 0;
}

int main()
{
	//For random number generator
	std::srand(static_cast<unsigned int>(std::time(0)));
	//Standard array
	std::array<Card, 52> myArray;
	int cardNumber{ 0 };
	for (int suits = 0; suits < static_cast<int>(CardSuits::TOTAL_SUITS); ++suits)
	{
		for (int ranks = 0; ranks < static_cast<int>(CardRanks::TOTAL_CARDS); ++ranks)
		{
			myArray[cardNumber].rank = static_cast<CardRanks>(ranks);
			myArray[cardNumber].suit = static_cast<CardSuits>(suits);
			++cardNumber;
		}
	}
	printDeck(myArray);
	shuffleDeck(myArray);
	printDeck(myArray);
	std::cout << getCardValue(myArray[0]);

	//To keep the cmd open
	while (true);
    return 0;
}