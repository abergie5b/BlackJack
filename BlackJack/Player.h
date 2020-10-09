#include <vector>

#include "Hand.h"
#include "Card.h"

class Player
{
public:
	Player(std::string name);
	bool WillHit();
	bool IsBusted();
	void TakeCard(Card&);
	void SetAnte(short unsigned int);
	short unsigned int GetAnte();
	short unsigned int GetHandValue();
	std::string GetName();
	void AddCash(short unsigned int);
	void PrintHand();

protected:
	std::string name;
	Hand hand;
private:
	short unsigned int ante;
	short unsigned int cash;
};

