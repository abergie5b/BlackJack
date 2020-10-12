#include <iostream>

#include "Dealer.h"


namespace BlackJack
{

	Dealer::Dealer()
		: Player("Dealer"), players(std::vector<Player>()), deck(Deck()), pot(100)
	{

	}

	Deck Dealer::GetDeck()
	{
		return deck;
	}

	void Dealer::AddPlayer(Player& player)
	{
		players.push_back(player);
	}

	bool Dealer::AllPlayersAreBusted()
	{
		for (Player& player : players)
			if (!player.IsBusted())
				return false;
		return true;
	}

	void Dealer::PlayTurn(Player& player)
	{
		std::cout << player.GetName() << std::endl;
		player.PrintHand();
		while (player.WillHit())
		{
			DealHit(player);
			player.PrintHand();
			if (player.IsBusted())
			{
				std::cout << player.GetName() << " busts" << std::endl;
				break;
			}
		}
	}

	void Dealer::PlayTurn()
	{
		std::cout << name << std::endl;
		PrintHand();
		while (ShouldHit())
		{
			DealHit(*this);
			PrintHand();
			if (IsBusted())
			{
				std::cout << name << " busts" << std::endl;
				break;
			}
		}
	}


	void Dealer::StartGame()
	{
		DealHands();
		std::cout << "Dealer" << std::endl;
		hand.FlipOne();
		for (Player& player : players)
			PlayTurn(player);

		if (!AllPlayersAreBusted())
			PlayTurn();
		EndGame();
	};

	void Dealer::EndGame()
	{
		CollectOrDistribute();
		if (hand.GetCards().size() <= DECK_SIZE/2)
			deck.Collect();
	};

	bool Dealer::ShouldHit()
	{
		return hand.GetDealerValue() <= 16;
	};

	void Dealer::DealHands()
	{
		for (Player& player : players)
		{
			DealHit(player);
			DealHit(player);
		}

		DealHit(*this);
		DealHit(*this);
	};

	void Dealer::DealHit(Player& player)
	{
		Card card = deck.Draw();
		player.TakeCard(card);
	};

	bool Dealer::WinsAgainst(Player& player)
	{
		return (!IsBusted() && (player.IsBusted() || player.GetHandValue() < hand.GetDealerValue()));
	}

	bool Dealer::LosesAgainst(Player& player)
	{
		return (IsBusted() || (!player.IsBusted() && player.GetHandValue() > hand.GetDealerValue()));
	}

	void Dealer::CollectOrDistribute()
	{
		for (Player& player : players)
		{
			if (WinsAgainst(player))
			{
				Collect(player);
			}
			else if (LosesAgainst(player))
			{
				Distribute(player);
			}
			// else draw
		}
	};

	void Dealer::Collect(Player& player)
	{
		std::cout << name << " collects " << player.GetAnte() << " from " << player.GetName() << std::endl;
		pot += player.GetAnte();
	}

	void Dealer::Distribute(Player& player)
	{
		if (player.GetAnte() <= pot)
		{
			std::cout << player.GetName() << " collects " << player.GetAnte() << " from " << name << std::endl;
			pot -= player.GetAnte();
			player.AddCash(player.GetAnte());
		}
	}

}

