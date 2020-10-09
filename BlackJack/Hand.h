#include <vector>

#include "Card.h"

class Hand
{
public:
	std::vector<Card> GetCards();
	short unsigned int GetValue();
	short unsigned int GetDealerValue();
	bool IsBusted();
	void push_back(Card&);
	void Print();
	void FlipOne();
private:
	std::vector<Card> cards;
};

