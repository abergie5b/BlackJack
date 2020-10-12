#ifndef __CARD_H_
#define __CARD_H_

#include "Types.h"

namespace BlackJack
{

	class Card
	{
	public:
		Card();
		Card(const Card&);
		Card& operator=(const Card&);
		Card(CardNames, SuiteNames);
		const CardNames GetName() const;
		const SuiteNames GetSuite() const;
		const short unsigned int GetHighValue() const;
		const short unsigned int GetLowValue() const;
	private:
		CardNames name;
		SuiteNames suite;
		short unsigned int highvalue;
		short unsigned int lowvalue;
	};

}

#endif
