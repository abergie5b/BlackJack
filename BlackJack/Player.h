#ifndef __PLAYER_H_
#define __PLAYER_H_

#include <vector>
#include <string>

#include "Hand.h"
#include "Card.h"

namespace BlackJack
{

	class Player
	{
	public:
		Player(std::string name);
		bool WillHit();
		bool IsBusted();
		void TakeCard(Card&);
		void SetAnte(uint32_t);
		uint32_t GetAnte();
		Hand GetHand();
		uint8_t GetHandValue();
		std::string GetName();
		void AddCash(uint32_t);
		void PrintHand();

	protected:
		std::string name;
		Hand hand;
	private:
		uint32_t ante;
		uint32_t cash;
	};
}

#endif
