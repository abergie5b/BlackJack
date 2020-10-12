#ifndef __DEALER_H_
#define __DEALER_H_

#include <vector>

#include "Deck.h"
#include "Player.h"

namespace BlackJack
{

	class Dealer : public Player
	{
	public:
		Dealer();
		void StartGame();
		void PlayTurn(Player& player);
		void AddPlayer(Player& player);

		// public for tests ...
		Deck GetDeck();
		bool ShouldHit();
		bool WinsAgainst(Player& player);
		bool LosesAgainst(Player& player);
		void DealHit(Player& player);
		void EndGame();
	private:
		void PlayTurn();
		bool AllPlayersAreBusted();
		void DealHands();
		void CollectOrDistribute();
		void Collect(Player& player);
		void Distribute(Player& player);

		//
		std::vector<Player> players;
		Deck deck;
		unsigned int pot;
	};

}

#endif

