#include <iostream>

#include "Dealer.h"


Dealer::Dealer()
	: Player("Dealer"), players(std::vector<Player>()), deck(Deck()), pot(100)
{

}

void Dealer::AddPlayer(Player player)
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

void Dealer::CollectOrDistribute()
{
	for (Player& player : players)
	{
		if (!IsBusted() && (player.IsBusted() || player.GetHandValue() < hand.GetDealerValue()))
		{
			Collect(player);
		}
		else if (IsBusted() || (!player.IsBusted() && player.GetHandValue() > hand.GetDealerValue()))
		{
			Distribute(player);
		}
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
