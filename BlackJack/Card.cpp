#include "Card.h"

Card::Card()
	: highvalue(0), lowvalue(0), name(""), suite("")
{

}

Card::Card(const Card& card)
	: highvalue(card.highvalue), lowvalue(card.lowvalue), name(card.name), suite(card.suite)
{

}

Card& Card::operator=(const Card& card)
{
	highvalue = card.highvalue;
	lowvalue = card.lowvalue;
	name = card.name;
	suite = card.suite;
	return *this;
}

Card::Card(const short unsigned int lowvalue, const short unsigned int highvalue, const std::string name)
	: lowvalue(lowvalue), highvalue(highvalue), name(name)
{

}

Card::Card(const short unsigned int lowvalue, const short unsigned int highvalue, const std::string name, const std::string suite)
	: lowvalue(lowvalue), highvalue(highvalue), name(name), suite(suite)
{

}

void Card::SetSuite(std::string suite)
{
	this->suite = suite;
}

const std::string Card::GetName() const
{
	return name;
};

const std::string Card::GetSuite() const
{
	return suite;
};

const short unsigned int Card::GetLowValue() const
{
	return lowvalue;
};


const short unsigned int Card::GetHighValue() const
{
	return highvalue;
};

