#include "Hand.h"
#include <iostream>

void Hand::push_back(Card& card)
{
	cards.push_back(card);
}

std::vector<Card> Hand::GetCards()
{
	return cards;
};

short unsigned int Hand::GetValue()
{
	short unsigned int minvalue = 0;
	for (Card& card : cards)
	{
		minvalue += card.GetLowValue();
	}

	bool aceCount = false;
	short unsigned int value = 0;
	for (Card& card : cards)
	{
		short unsigned int highvalue = card.GetHighValue();
		short unsigned int lowvalue = card.GetLowValue();
		if (minvalue <= 10 and not aceCount)
		{
			value += card.GetHighValue();
			aceCount = true;
		}
		else
			value += card.GetLowValue();
	}
	return value;
};

short unsigned int Hand::GetDealerValue()
{
	short unsigned int value = 0;
	for (Card& card : cards)
	{
		short unsigned int highvalue = card.GetHighValue();
		short unsigned int lowvalue = card.GetLowValue();
		if (value + highvalue <= 21 && value + highvalue >= 17)
			value += highvalue;
		else
			value += lowvalue;
	}
	return value;
};

bool Hand::IsBusted()
{
	return GetValue() > 21;
};


void Hand::Print()
{
	std::cout << "Points: " << GetValue() << std::endl;
	for (Card& card : cards)
	{
		std::cout << '\t' << card.GetName() << " of " << card.GetSuite() << std::endl;
	}
}

void Hand::FlipOne()
{
	std::cout << '\t' << cards[1].GetName() << " of " << cards[1].GetSuite() << std::endl;
}

