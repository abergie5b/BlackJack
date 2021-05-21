#include "Dealer.h"
#include "Game.h"

#include <iostream>

namespace BlackJack
{

    Game::Game(uint8_t nPlayers, uint32_t nMinAnte)
        : nPlayers(nPlayers),
          nMinAnte(nMinAnte)
    {
    }

    Game::Game()
    {
        this->nPlayers = 0;
        this->nMinAnte = 0;
    };

    void Game::SetOptions()
    {
        std::string input;
        std::cout << "#Players: ";
        std::cin >> input;
        this->nPlayers = std::strtol(input.c_str(), 0, 10);

        std::cout << "Min Ante: ";
        std::cin >> input;
        std::cout << std::endl;
        this->nMinAnte = std::strtol(input.c_str(), 0, 10);
    }

    void Game::Play()
    {
        Dealer dealer(*this);
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
            Play();
    };

}
