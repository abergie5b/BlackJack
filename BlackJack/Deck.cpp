#include <random>
#include <time.h>

#include "Deck.h"
#include "Types.h"

Deck::Deck()
{
	srand(time(0));
	Collect();
}

Card Deck::Draw()
{
	Card card;
	if (!cards.empty())
	{
		card = cards.front();
		cards.pop_front();
	}
	return card;
}

void Deck:: Shuffle()
{
	std::random_shuffle(cards.begin(), cards.end());
};

void Deck::Collect()
{
	std::deque<Card> _cards;
	for (std::string suite : Suites)
	{
		for (Card c : Cards)
		{ 
			c.SetSuite(suite);
			_cards.push_back(c);
		}
	}
	cards = _cards;
	Shuffle();
};

