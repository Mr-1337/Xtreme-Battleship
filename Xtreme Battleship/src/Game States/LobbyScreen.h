#pragma once
#include "GameState.h"
#include "../Core/GameSettings.h"
#include "../UI/MenuButton.h"
#include "../Gameplay/Player.h"
class LobbyScreen :
	public GameState
{
public:
	LobbyScreen(SDL_Window* window);
	~LobbyScreen();
	void draw() override;
	void update() override;
private:
	int w, h;
	std::vector <std::unique_ptr<Player>> m_playerList;
	std::vector <std::shared_ptr<Text>> m_nameText;
	MenuButton* m_addAI;
	MenuButton* m_start;
	void addAI();
};

