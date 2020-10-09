#ifndef __CARD_H_
#define __CARD_H_

#include <string>

class Card
{
public:
	Card();
	Card(const Card&);
	Card& operator=(const Card&);
	Card(const short unsigned int, const short unsigned int, const std::string);
	Card(const short unsigned int, const short unsigned int, const std::string, const std::string);
	void SetSuite(std::string);
	const std::string GetName() const;
	const std::string GetSuite() const;
	const short unsigned int GetHighValue() const;
	const short unsigned int GetLowValue() const;
private:
	std::string name;
	std::string suite;
	short unsigned int highvalue;
	short unsigned int lowvalue;
};

#endif
