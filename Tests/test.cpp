#include "pch.h"

#include "../BlackJack/Player.h"
#include "../BlackJack/Dealer.h"

TEST(TestCaseName, TestPlayerIsBusted) {
	Player player("Test");
	player.TakeCard(Card(10, 10, "King", "Clubs"));
	player.TakeCard(Card(10, 10, "Queen", "Clubs"));
	player.TakeCard(Card(10, 10, "Jack", "Clubs"));
	assert(player.IsBusted());
}

