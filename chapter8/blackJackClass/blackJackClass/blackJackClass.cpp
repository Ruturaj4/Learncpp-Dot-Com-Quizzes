// blackJackClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <array>
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()

class Card
{
public:
	enum class CardSuit
	{
		SUIT_CLUB,
		SUIT_DIAMOND,
		SUIT_HEART,
		SUIT_SPADE,
		MAX_SUITS
	};

	enum class CardRank
	{
		RANK_2,
		RANK_3,
		RANK_4,
		RANK_5,
		RANK_6,
		RANK_7,
		RANK_8,
		RANK_9,
		RANK_10,
		RANK_JACK,
		RANK_QUEEN,
		RANK_KING,
		RANK_ACE,
		MAX_RANKS
	};
private:
	CardRank m_rank;
	CardSuit m_suit;
public:
	Card(CardRank rank = CardRank::RANK_ACE, CardSuit suit = CardSuit::SUIT_CLUB) : m_rank(rank), m_suit(suit)
	{

	}
	void printCard() const
	{
		switch (m_rank)
		{
		case CardRank::RANK_2:		std::cout << '2'; break;
		case CardRank::RANK_3:		std::cout << '3'; break;
		case CardRank::RANK_4:		std::cout << '4'; break;
		case CardRank::RANK_5:		std::cout << '5'; break;
		case CardRank::RANK_6:		std::cout << '6'; break;
		case CardRank::RANK_7:		std::cout << '7'; break;
		case CardRank::RANK_8:		std::cout << '8'; break;
		case CardRank::RANK_9:		std::cout << '9'; break;
		case CardRank::RANK_10:		std::cout << 'T'; break;
		case CardRank::RANK_JACK:		std::cout << 'J'; break;
		case CardRank::RANK_QUEEN:	std::cout << 'Q'; break;
		case CardRank::RANK_KING:		std::cout << 'K'; break;
		case CardRank::RANK_ACE:		std::cout << 'A'; break;
		}

		switch (m_suit)
		{
		case CardSuit::SUIT_CLUB:		std::cout << 'C'; break;
		case CardSuit::SUIT_DIAMOND:	std::cout << 'D'; break;
		case CardSuit::SUIT_HEART:	std::cout << 'H'; break;
		case CardSuit::SUIT_SPADE:	std::cout << 'S'; break;
		}
	}

	int getCardValue() const
	{
		switch (m_rank)
		{
		case CardRank::RANK_2:		return 2;
		case CardRank::RANK_3:		return 3;
		case CardRank::RANK_4:		return 4;
		case CardRank::RANK_5:		return 5;
		case CardRank::RANK_6:		return 6;
		case CardRank::RANK_7:		return 7;
		case CardRank::RANK_8:		return 8;
		case CardRank::RANK_9:		return 9;
		case CardRank::RANK_10:		return 10;
		case CardRank::RANK_JACK:		return 10;
		case CardRank::RANK_QUEEN:	return 10;
		case CardRank::RANK_KING:		return 10;
		case CardRank::RANK_ACE:		return 11;
		}

		return 0;
	}
};

class Deck
{
	std::array<Card, 52> m_deck;
	int m_cardIndex{ 0 };
	void swapCard(Card &a, Card &b)
	{
		Card temp = a;
		a = b;
		b = temp;
	}
	// Generate a random number between min and max (inclusive)
	// Assumes srand() has already been called
	int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
		// evenly distribute the random number across our range
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}
public:
	Deck()
	{
		// We could initialize each card individually, but that would be a pain.  Let's use a loop.
		int card = 0;
		for (int suit = 0; suit < static_cast<int>(Card::CardSuit::MAX_SUITS); ++suit)
			for (int rank = 0; rank < static_cast<int>(Card::CardRank::MAX_RANKS); ++rank)
			{
				m_deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
				++card;
			}
	}
	void printDeck()
	{
		for (const auto &card : m_deck)
		{
			card.printCard();
			std::cout << ' ';
		}

		std::cout << '\n';
	}
	void shuffleDeck()
	{
		// Step through each card in the deck
		for (int index = 0; index < 52; ++index)
		{
			// Pick a random card, any card
			int swapIndex = getRandomNumber(0, 51);
			// Swap it with the current card
			swapCard(m_deck[index], m_deck[swapIndex]);
		}
		m_cardIndex = 0;
	}
	const Card& dealCard()
	{
		return m_deck[m_cardIndex++];
	}
};

char getPlayerChoice()
{
	std::cout << "(h) to hit, or (s) to stand: ";
	char choice;
	do
	{
		std::cin >> choice;
	} while (choice != 'h' && choice != 's');

	return choice;
}

enum class Result
{
	MATCH_WON, MATCH_LOST, MATCH_DRAWN,
};

Result playBlackjack(Deck deck)
{

	int playerTotal = 0;
	int dealerTotal = 0;

	// Deal the dealer one card
	dealerTotal += deck.dealCard().getCardValue();
	std::cout << "The dealer is showing: " << dealerTotal << '\n';

	// Deal the player two cards
	playerTotal += deck.dealCard().getCardValue();
	playerTotal += deck.dealCard().getCardValue();

	// Player goes first
	while (1)
	{
		std::cout << "You have: " << playerTotal << '\n';
		char choice = getPlayerChoice();
		if (choice == 's')
			break;

		playerTotal += deck.dealCard().getCardValue();

		// See if the player busted
		if (playerTotal > 21)
			return Result::MATCH_LOST;
	}

	// If player hasn't busted, dealer goes until he has at least 17 points
	while (dealerTotal < 17)
	{
		dealerTotal += deck.dealCard().getCardValue();
		std::cout << "The dealer now has: " << dealerTotal << '\n';
	}

	// If dealer busted, player wins
	if (dealerTotal > 21)
		return Result::MATCH_WON;

	if (playerTotal > dealerTotal)
	{
		return Result::MATCH_WON;
	}
	else if (playerTotal < dealerTotal)
	{
		return Result::MATCH_LOST;
	}
	else
	{
		return Result::MATCH_DRAWN;
	}
}

int main()
{
	while (true)
	{
		std::cout << "Let's begin\n";
		srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
		rand(); // If using Visual Studio, discard first random value
		Deck deck;
		deck.printDeck();
		deck.shuffleDeck();
		deck.printDeck();

		/*std::cout << "The first card has value: " << deck.dealCard().getCardValue() << '\n';
		std::cout << "The second card has value: " << deck.dealCard().getCardValue() << '\n';*/
		Result result{ playBlackjack(deck) };
		if (result == Result::MATCH_WON)
		{
			std::cout << "You win!\n\n";
		}
		else if (result == Result::MATCH_LOST)
		{
			std::cout << "You lose!\n\n";
		}
		else if (result == Result::MATCH_DRAWN)
		{
			std::cout << "Match Drawn!\n\n";
		}
	}

	//To keep the cmd open
	while (true);
	return 0;
}