#include <string>
#include <vector>

#include "Card.h"


const std::vector<std::string> Suites = 
{
	"Hearts",
	"Diamonds",
	"Clubs",
	"Spades"
};


const std::vector<Card> Cards =
{
	Card(2, 2, "Two"),
	Card(3, 3, "Three"),
	Card(4, 4, "Four"),
	Card(5, 5, "Five"),
	Card(6, 6, "Six"),
	Card(7, 7, "Seven"),
	Card(8, 8, "Eight"),
	Card(9, 9, "Nine"),
	Card(10, 10, "Ten"),
	Card(10, 10, "Jack"),
	Card(10, 10, "Queen"),
	Card(10, 10, "King"),
	Card(1, 11, "Ace")
};

