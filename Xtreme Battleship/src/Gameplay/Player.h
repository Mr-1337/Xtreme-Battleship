#pragma once
#include "../Graphics/AnimatedSprite.h"
#include "GameWorld.h"
#include <vector>

class Player
{
public:
	Player(std::string name);
	~Player();
	inline std::string getName() const { return m_name; }
	static int playerCount;
private:
	std::string m_name;
};

