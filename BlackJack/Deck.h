#include <deque>
#include "Card.h"

class Deck
{
public:
	Deck();
	Card Draw();
	void Shuffle();
	void Collect();
private:
	std::deque<Card> cards;
};

