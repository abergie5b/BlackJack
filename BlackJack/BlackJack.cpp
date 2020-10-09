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
        Player player("Player");
        dealer.AddPlayer(player);
    }
	dealer.StartGame();
    std::string playAgain;
    std::cout << "Play Again?" << std::endl;
    std::cin >> playAgain;
    if (playAgain == "y")
        Play(nPlayers);
};

