#ifndef __GAME_H_
#define __GAME_H_

class Dealer;

namespace BlackJack
{
	class Game
	{
		public:
			uint32_t nMinAnte;

			Game();
			Game(uint8_t nPlayers, uint32_t nMinAnte);
			void Play();
			void SetOptions();
		private:
			uint8_t nPlayers;
	};

}

#endif
