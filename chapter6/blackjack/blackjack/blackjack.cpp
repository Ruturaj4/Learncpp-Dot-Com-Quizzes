// blackjack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <array>
#include <ctime>
#include <cstdlib>

enum class GameResult
{
	PLAYER_WIN,
	PLAYER_LOOSE,
	MATCH_DRAWN,
};

enum class CardRank
{
	TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN,
	KING, ACE, MAX_RANK,
};

enum class CardSuit
{
	CLUBS, DIAMONDS, HEARTS, SPADES, MAX_SUIT,
};

struct Card
{
	CardRank rank;
	CardSuit suit;
};

void printCard(const Card &card)
{
	switch (card.rank)
	{
	case CardRank::TWO: std::cout << "2"; break;
	case CardRank::THREE: std::cout << "3"; break;
	case CardRank::FOUR: std::cout << "4"; break;
	case CardRank::FIVE: std::cout << "5"; break;
	case CardRank::SIX: std::cout << "6"; break;
	case CardRank::SEVEN: std::cout << "7"; break;
	case CardRank::EIGHT: std::cout << "8"; break;
	case CardRank::NINE: std::cout << "9"; break;
	case CardRank::TEN: std::cout << "10"; break;
	case CardRank::JACK: std::cout << "J"; break;
	case CardRank::QUEEN: std::cout << "Q"; break;
	case CardRank::KING: std::cout << "K"; break;
	case CardRank::ACE: std::cout << "A"; break;
	default: std::cout << "?";
		break;
	}
	switch (card.suit)
	{
	case CardSuit::CLUBS: std::cout << "C"; break;
	case CardSuit::DIAMONDS: std::cout << "D"; break;
	case CardSuit::HEARTS: std::cout << "H"; break;
	case CardSuit::SPADES: std::cout << "S"; break;
	default: std::cout << "?";
		break;
	}
}

void printDeck(std::array<Card, 52> &deck)
{
	for (const auto &index : deck)
	{
		printCard(index);
		std::cout << " ";
	}
	std::cout << "\n";
}

void swapCard(Card &firstCard, Card &secondCard)
{
	Card temp = firstCard;
	firstCard = secondCard;
	secondCard = temp;
}

int randomNumber(int min, int max)
{
	rand();
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return min + static_cast<int>((max - min + 1) * rand() * fraction);
}

void shuffleDeck(std::array<Card, 52> &deck)
{
	int randNo{ 0 };
	for (int index = 0; index < 52; ++index)
	{
		randNo = randomNumber(0, 51);
		swapCard(deck[index], deck[randNo]);
	}
}

 int getCardValue(const Card &card)
{
	 switch (card.rank)
	 {
	 case CardRank::TWO: return 2;
	 case CardRank::THREE: return 3;
	 case CardRank::FOUR: return 4;
	 case CardRank::FIVE: return 5;
	 case CardRank::SIX: return 6;
	 case CardRank::SEVEN: return 7;
	 case CardRank::EIGHT: return 8;
	 case CardRank::NINE: return 9;
	 case CardRank::TEN:
	 case CardRank::JACK:
	 case CardRank::QUEEN:
	 case CardRank::KING: return 10;
	 case CardRank::ACE: return 11;
	 default:
		 return 0;
	 }
}

 GameResult playBlackjack(std::array<Card, 52> &deck)
 {
	 Card *cardPtr = &deck[0];
	 int playerScore{ 0 };
	 int dealerScore{ 0 };
	 int playerAces{ 0 };
	 int dealerAces{ 0 };
	 dealerScore = getCardValue(*cardPtr);
	 std::cout << "The dealer has: ";
	 printCard(*cardPtr);
	 if (cardPtr->rank == CardRank::ACE)
	 {
		 ++dealerAces;
	 }
	 std::cout << "\n";
	 std::cout << "The dealer has " << dealerAces << " ace/s\n";
	 *cardPtr++;
	 std::cout << "The dealer's score is: " << dealerScore << "\n";
	 playerScore = getCardValue(*cardPtr) + getCardValue(*cardPtr++);
	 std::cout << "The player has: ";
	 if (cardPtr->rank == CardRank::ACE)
	 {
		 ++playerAces;
	 }
	 if ((cardPtr - 1)->rank == CardRank::ACE)
	 {
		 ++playerAces;
	 }
	 printCard(*(cardPtr - 1));
	 std::cout << " and ";
	 printCard(*cardPtr);
	 std::cout << "\n";
	 if (playerScore != 21)
	 {
		 std::cout << "You have " << playerAces << " ace/s\n";
		 while (playerAces > 0)
		 {
			 playerScore -= 10;
			 --playerAces;
		 }
	 }
	 std::cout << "Your score is: " << playerScore << "\n";
	 if (playerScore == 21)
	 {
		 return GameResult::PLAYER_WIN;
	 }
	 while (true)
	 {
		 std::cout << "Do you want to Hit ('h' to hit) or Stand ('s' to stand)? ";
		 char playerDecision;
		 std::cin >> playerDecision;
		 if (playerDecision == 'h')
		 {
			 playerScore += getCardValue(*cardPtr);
			 if (playerScore == 21)
			 {
				 std::cout << "Your score is: " << playerScore << "\n";
				 return GameResult::PLAYER_WIN;
			 }
			 if (cardPtr->rank == CardRank::ACE)
			 {
				 ++playerAces;
			 }
			 *cardPtr++;
			 if (playerScore != 21)
			 {
				 std::cout << "You have " << playerAces << " ace/s\n";
				 while (playerAces > 0)
				 {
					 playerScore -= 10;
					 --playerAces;
				 }
			 }
			 std::cout << "Your score is: " << playerScore << "\n";
			 if (playerScore > 21)
			 {
				 std::cout << "You are busted\n";
				 return GameResult::PLAYER_LOOSE;
			 }
			 else if (playerScore < 21)
			 {
				 continue;
			 }
		 }
		 else if (playerDecision == 's')
		 {
			 if (playerScore < dealerScore)
			 {
				 return GameResult::PLAYER_LOOSE;
			 }
			 else if (playerScore > dealerScore)
			 {
				 do
				 {
					 dealerScore += getCardValue(*cardPtr);
					 if (dealerScore == 21)
					 {
						 std::cout << "The dealer score is: " << dealerScore << "\n";
						 return GameResult::PLAYER_LOOSE;
					 }
					 if (cardPtr->rank == CardRank::ACE)
					 {
						 ++dealerAces;
					 }
					 *cardPtr++;
					 if (dealerScore != 21)
					 {
						 std::cout << "The dealer has " << dealerAces << " ace/s\n";
						 while (dealerAces > 0)
						 {
							 dealerScore -= 10;
							 --dealerAces;
						 }
					 }
				 } while (dealerScore <= 17);
				 std::cout << "The dealer score is: " << dealerScore << "\n";
				 if (dealerScore > 21)
				 {
					 std::cout << "The dealer is busted!\n";
					 return GameResult::PLAYER_WIN;
				 }
				 else if (dealerScore < playerScore)
				 {
					 return GameResult::PLAYER_WIN;
				 }
				 else if ((dealerScore > playerScore) && (dealerScore <= 21))
				 {
					 return GameResult::PLAYER_LOOSE;
				 }
				 else if (dealerScore == playerScore)
				 {
					 return GameResult::MATCH_DRAWN;
				 }
			 }
		 }
	 }
	 
 }

int main()
{
	std::array<Card, 52> deck;
	int cardNumber{ 0 };
	int card{ 0 };
	for (int suit = 0; suit < static_cast<int>(CardSuit::MAX_SUIT); ++suit)
	{
		for (int rank = 0; rank < static_cast<int>(CardRank::MAX_RANK); ++rank)
		{
			deck[card].rank = static_cast<CardRank>(rank);
			deck[card].suit = static_cast<CardSuit>(suit);
			++card;
		}
	}
	char playAgain{ 'y' };
	while (playAgain == 'y')
	{
		srand(static_cast<unsigned int> (time(0)));
		printDeck(deck);
		shuffleDeck(deck);
		printDeck(deck);
		GameResult gameResult;
		gameResult = playBlackjack(deck);
		if (gameResult == GameResult::PLAYER_WIN)
		{
			std::cout << "You win!\n\n";
		}
		else if (gameResult == GameResult::PLAYER_LOOSE)
		{
			std::cout << "You loose!\n\n";
		}
		else if (gameResult == GameResult::MATCH_DRAWN)
		{
			std::cout << "Match is drawn!\n\n";
		}
		while (true)
		{
			std::cout << "Would you like to play again? (y or n)\n";
			std::cin >> playAgain;
			std::cin.ignore(32767, '\n');
			if (playAgain == 'y')
				break;
			else if (playAgain == 'n')
				return 0;
			else
				continue;
		}
	}
}