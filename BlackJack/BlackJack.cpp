#include "Dealer.h"
#include "BlackJack.h"

#include <iostream>

BlackJack::BlackJack()
{
};

void BlackJack::Play(short unsigned int nPlayers)
{
    Dealer dealer;
    for (int x = 0; x < nPlayers; x++)
    {
        dealer.AddPlayer(Player("Player"));
    }
	dealer.StartGame();
    std::string playAgain;
    std::cout << "Play Again?" << std::endl;
    std::cin >> playAgain;
    if (playAgain == "y")
        Play(nPlayers);
};

