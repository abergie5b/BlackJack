#include "pch.h"

#include "../BlackJack/Game.h"

using namespace BlackJack;


TEST(TestCaseName, DeckInit)
{
	Game game(1, 2);
	BlackJack::Dealer dealer(game);
	EXPECT_TRUE(dealer.GetDeck().GetCards().size() == DECK_SIZE);
}


TEST(TestCaseName, TestDealHit1)
{
	Game game(1, 2);
	BlackJack::Dealer dealer(game);
	Player player("Test");
	dealer.DealHit(player);
	dealer.DealHit(player);
	dealer.DealHit(player);
	EXPECT_TRUE(player.GetHand().GetCards().size() == 3);
	EXPECT_TRUE(dealer.GetDeck().GetCards().size() == DECK_SIZE - 3);
}

TEST(TestCaseName, TestDealHit2)
{
	Game game(1, 2);
	BlackJack::Dealer dealer(game);
	Player player1("Test1");
	Player player2("Test2");
	dealer.DealHit(dealer);
	dealer.DealHit(dealer);
	dealer.DealHit(player1);
	dealer.DealHit(player1);
	dealer.DealHit(player2);
	dealer.DealHit(player2);
	EXPECT_TRUE(player1.GetHand().GetCards().size() == 2);
	EXPECT_TRUE(player2.GetHand().GetCards().size() == 2);
	EXPECT_TRUE(dealer.GetHand().GetCards().size() == 2);
	EXPECT_TRUE(dealer.GetDeck().GetCards().size() == DECK_SIZE - 6);
}

TEST(TestCaseName, TestPlayerIsBusted1) {
	Player player("Test");
	player.TakeCard(Card(CardNames::TEN, SuiteNames::CLUBS));
	player.TakeCard(Card(CardNames::FIVE, SuiteNames::CLUBS));
	player.TakeCard(Card(CardNames::JACK, SuiteNames::CLUBS));
	EXPECT_TRUE(player.IsBusted());
}


TEST(TestCaseName, TestPlayerIsBusted2) {
	Player player("Test");
	player.TakeCard(Card(CardNames::TWO, SuiteNames::CLUBS));
	player.TakeCard(Card(CardNames::THREE, SuiteNames::CLUBS));
	player.TakeCard(Card(CardNames::ACE, SuiteNames::CLUBS));
	player.TakeCard(Card(CardNames::SEVEN, SuiteNames::HEARTS));
	player.TakeCard(Card(CardNames::NINE, SuiteNames::DIAMONDS));
	EXPECT_TRUE(player.IsBusted());
}

TEST(TestCaseName, TestPlayerIsNotBusted) {
	Player player("Test");
	player.TakeCard(Card(CardNames::TWO, SuiteNames::SPADES));
	player.TakeCard(Card(CardNames::ACE, SuiteNames::DIAMONDS));
	player.TakeCard(Card(CardNames::ACE, SuiteNames::HEARTS));
	player.TakeCard(Card(CardNames::EIGHT, SuiteNames::DIAMONDS));
	EXPECT_FALSE(player.IsBusted());
	EXPECT_TRUE(player.GetHand().GetValue() == 12);
}

TEST(TestCaseName, TestDealerShouldNotHitAces1)
{
	Game game(1, 2);
	BlackJack::Dealer dealer(game);
	dealer.TakeCard(Card(CardNames::ACE, SuiteNames::CLUBS));
	dealer.TakeCard(Card(CardNames::SIX, SuiteNames::CLUBS));
	EXPECT_FALSE(dealer.ShouldHit());
	EXPECT_FALSE(dealer.IsBusted());
}

TEST(TestCaseName, TestDealerShouldNotHitAces2)
{
	Game game(1, 2);
	BlackJack::Dealer dealer(game);
	dealer.TakeCard(Card(CardNames::THREE, SuiteNames::CLUBS));
	dealer.TakeCard(Card(CardNames::ACE, SuiteNames::CLUBS));
	dealer.TakeCard(Card(CardNames::THREE, SuiteNames::HEARTS));
	EXPECT_FALSE(dealer.ShouldHit());
	EXPECT_FALSE(dealer.IsBusted());
}

TEST(TestCaseName, TestDealerShouldNotHitAces3)
{
	Game game(1, 2);
	BlackJack::Dealer dealer(game);
	dealer.TakeCard(Card(CardNames::ACE, SuiteNames::CLUBS));
	dealer.TakeCard(Card(CardNames::ACE, SuiteNames::HEARTS));
	dealer.TakeCard(Card(CardNames::FIVE, SuiteNames::HEARTS));
	EXPECT_FALSE(dealer.ShouldHit());
	EXPECT_FALSE(dealer.IsBusted());
}

TEST(TestCaseName, TestDealerShouldHitAces1)
{
	Game game(1, 2);
	BlackJack::Dealer dealer(game);
	dealer.TakeCard(Card(CardNames::FIVE, SuiteNames::HEARTS));
	dealer.TakeCard(Card(CardNames::ACE, SuiteNames::HEARTS));
	EXPECT_TRUE(dealer.ShouldHit());
	EXPECT_FALSE(dealer.IsBusted());
}

TEST(TestCaseName, TestDealerShouldHitAces2)
{
	Game game(1, 2);
	BlackJack::Dealer dealer(game);
	dealer.TakeCard(Card(CardNames::TWO, SuiteNames::CLUBS));
	dealer.TakeCard(Card(CardNames::ACE, SuiteNames::HEARTS));
	dealer.TakeCard(Card(CardNames::THREE, SuiteNames::HEARTS));
	EXPECT_TRUE(dealer.ShouldHit());
	EXPECT_FALSE(dealer.IsBusted());
}

TEST(TestCaseName, TestDealerShouldHitAces3)
{
	Game game(1, 2);
	BlackJack::Dealer dealer(game);
	dealer.TakeCard(Card(CardNames::ACE, SuiteNames::CLUBS));
	dealer.TakeCard(Card(CardNames::ACE, SuiteNames::HEARTS));
	dealer.TakeCard(Card(CardNames::FOUR, SuiteNames::HEARTS));
	EXPECT_TRUE(dealer.ShouldHit());
	EXPECT_FALSE(dealer.IsBusted());
}

TEST(TestCaseName, PlayerWins)
{
	Game game(1, 2);
	BlackJack::Dealer dealer(game);
	Player player("test");
	player.TakeCard(Card(CardNames::NINE, SuiteNames::CLUBS));
	player.TakeCard(Card(CardNames::NINE, SuiteNames::HEARTS));
	dealer.TakeCard(Card(CardNames::EIGHT, SuiteNames::CLUBS));
	dealer.TakeCard(Card(CardNames::EIGHT, SuiteNames::HEARTS));
	EXPECT_TRUE(dealer.LosesAgainst(player));
	EXPECT_FALSE(dealer.WinsAgainst(player));
}

TEST(TestCaseName, DealerWins)
{
	Game game(1, 2);
	BlackJack::Dealer dealer(game);
	Player player("test");
	dealer.TakeCard(Card(CardNames::NINE, SuiteNames::CLUBS));
	dealer.TakeCard(Card(CardNames::NINE, SuiteNames::HEARTS));
	player.TakeCard(Card(CardNames::EIGHT, SuiteNames::CLUBS));
	player.TakeCard(Card(CardNames::EIGHT, SuiteNames::HEARTS));
	EXPECT_TRUE(dealer.WinsAgainst(player));
	EXPECT_FALSE(dealer.LosesAgainst(player));
}

TEST(TestCaseName, Draw)
{
	Game game(1, 2);
	BlackJack::Dealer dealer(game);
	Player player("test");
	dealer.TakeCard(Card(CardNames::EIGHT, SuiteNames::DIAMONDS));
	dealer.TakeCard(Card(CardNames::EIGHT, SuiteNames::SPADES));
	player.TakeCard(Card(CardNames::EIGHT, SuiteNames::CLUBS));
	player.TakeCard(Card(CardNames::EIGHT, SuiteNames::HEARTS));
	EXPECT_FALSE(dealer.WinsAgainst(player));
	EXPECT_FALSE(dealer.LosesAgainst(player));
}

TEST(TestCaseName, BlackJackPlayer1)
{
	Player player("test");
	player.TakeCard(Card(CardNames::FIVE, SuiteNames::HEARTS));
	player.TakeCard(Card(CardNames::ACE, SuiteNames::DIAMONDS));
	player.TakeCard(Card(CardNames::TEN, SuiteNames::DIAMONDS));
	player.TakeCard(Card(CardNames::FIVE, SuiteNames::CLUBS));
	EXPECT_TRUE(player.GetHandValue() == BLACKJACK);
	EXPECT_FALSE(player.IsBusted());
}

TEST(TestCaseName, BlackJackPlayer2)
{
	Player player("test");
	player.TakeCard(Card(CardNames::TWO, SuiteNames::HEARTS));
	player.TakeCard(Card(CardNames::ACE, SuiteNames::DIAMONDS));
	player.TakeCard(Card(CardNames::ACE, SuiteNames::HEARTS));
	player.TakeCard(Card(CardNames::SEVEN, SuiteNames::CLUBS));
	EXPECT_TRUE(player.GetHandValue() == BLACKJACK);
	EXPECT_FALSE(player.IsBusted());
}

TEST(TestCaseName, AcesTest1)
{
	Player player("test");
	player.TakeCard(Card(CardNames::ACE, SuiteNames::HEARTS));
	player.TakeCard(Card(CardNames::ACE, SuiteNames::DIAMONDS));
	player.TakeCard(Card(CardNames::ACE, SuiteNames::CLUBS));
	player.TakeCard(Card(CardNames::ACE, SuiteNames::SPADES));
	EXPECT_TRUE(player.GetHandValue() == 14);
	EXPECT_FALSE(player.IsBusted());
}

TEST(TestCaseName, AcesTest2)
{
	Player player("test");
	player.TakeCard(Card(CardNames::ACE, SuiteNames::HEARTS));
	player.TakeCard(Card(CardNames::JACK, SuiteNames::DIAMONDS));
	EXPECT_TRUE(player.GetHandValue() == BLACKJACK);
	EXPECT_FALSE(player.IsBusted());
}

TEST(TestCaseName, AcesTest3)
{
	Player player("test");
	player.TakeCard(Card(CardNames::ACE, SuiteNames::HEARTS));
	player.TakeCard(Card(CardNames::JACK, SuiteNames::DIAMONDS));
	player.TakeCard(Card(CardNames::JACK, SuiteNames::HEARTS));
	EXPECT_TRUE(player.GetHandValue() == BLACKJACK);
	EXPECT_FALSE(player.IsBusted());
}

TEST(TestCaseName, AcesTest4)
{
	Player player("test");
	player.TakeCard(Card(CardNames::ACE, SuiteNames::HEARTS));
	player.TakeCard(Card(CardNames::ACE, SuiteNames::CLUBS));
	player.TakeCard(Card(CardNames::JACK, SuiteNames::DIAMONDS));
	player.TakeCard(Card(CardNames::NINE, SuiteNames::HEARTS));
	EXPECT_TRUE(player.GetHandValue() == BLACKJACK);
	EXPECT_FALSE(player.IsBusted());
}

TEST(TestCaseName, DealerCollects50PercentDeckSize)
{
	Game game(1, 2);
	BlackJack::Dealer dealer(game);
	Player player("test");
	for (int x = 0; x < DECK_SIZE / 2; x++)
		dealer.DealHit(player);
	dealer.EndGame();
	EXPECT_TRUE(dealer.GetDeck().GetCards().size() == DECK_SIZE);
}


