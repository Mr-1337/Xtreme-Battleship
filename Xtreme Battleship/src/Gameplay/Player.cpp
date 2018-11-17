#include "Player.h"

int Player::playerCount = 0;

Player::Player(std::string name) 
	: m_name(name)
{
	std::cout << "Welcome aboard " << m_name << std::endl;
	playerCount++;
}

Player::~Player()
{
	std::cout << "Bye bye" << std::endl;
	playerCount--;
}