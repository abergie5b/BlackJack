#include <iostream>

#include "Player.h"

Player::Player(std::string name)
	: name(name), hand(Hand()), ante(2), cash(100)
{

}

void Player::PrintHand()
{
	hand.Print();
}

bool Player::IsBusted()
{
	return hand.IsBusted();
};

bool Player::WillHit()
{
	std::string hit;
	std::cout << "Hit?" << std::endl;
	std::cin >> hit;
	return (hit == "y");
};

void Player::TakeCard(Card& card)
{
	hand.push_back(card);
};

short unsigned int Player::GetHandValue()
{
	return hand.GetValue();
}

void Player::SetAnte(short unsigned int ante)
{
	this->ante = ante;
};

short unsigned int Player::GetAnte()
{
	return ante;
};

std::string Player::GetName()
{
	return name;
};

void Player::AddCash(short unsigned int cash)
{
	this->cash += cash;
};

