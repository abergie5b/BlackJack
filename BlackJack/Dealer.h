#include <vector>

#include "Deck.h"
#include "Player.h"

class Dealer : public Player
{
public:
	Dealer();
	void StartGame();
	void PlayTurn(Player& player);
	void AddPlayer(Player& player);
private:
	void PlayTurn();
	bool ShouldHit();
	bool AllPlayersAreBusted();
	void DealHands();
	void DealHit(Player& player);
	void EndGame();
	void CollectOrDistribute();
	void Collect(Player& player);
	void Distribute(Player& player);

	//
	std::vector<Player> players;
	Deck deck;
	unsigned int pot;
};

