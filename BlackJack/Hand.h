#ifndef __HAND_H_
#define __HAND_H_

#include <vector>

#include "Card.h"

namespace BlackJack
{

	class Hand
	{
	public:
		std::vector<Card> GetCards();
		short unsigned int GetValue();
		short unsigned int GetDealerValue();
		bool IsBusted();
		void push_back(Card&);
		void Print();
		void Print(Card&);
		void FlipOne();
	private:
		std::vector<Card> cards;
	};

}

#endif

