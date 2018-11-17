#include "LobbyScreen.h"



LobbyScreen::LobbyScreen(SDL_Window* window): 
	GameState(window)
{
	GameSettings::getDimensions(&w, &h);
	m_addAI = new  MenuButton(m_renderer, "Assets/Font/halo3.ttf", "Add AI");
	m_start = new MenuButton(m_renderer, "Assets/Font/halo3.ttf", "Start Game");

	m_addAI->onClick = [this] { addAI(); };
	m_start->onClick = [this] { request.state = STATE_QUIT; };

	m_playerList.push_back(std::make_unique<Player>("Player 1"));

	m_nameText.reserve(500);
	m_nameText.push_back(std::make_shared<Text>(m_renderer, m_playerList[0]->getName()));
	m_nameText[0]->load("Assets/Font/halo3.ttf", 14);
	m_nameText[0]->setY(60);

	m_start->setX(200);
}


LobbyScreen::~LobbyScreen()
{
}


void LobbyScreen::addAI()
{
	m_playerList.push_back(std::make_unique<Player>("AI Player " + std::to_string(Player::playerCount)));
	m_nameText.push_back((std::make_shared<Text>(m_renderer, "texty")));
	auto iter = m_nameText.end();
	iter--;
	(*iter)->load("Assets/Font/halo3.ttf", 18);
	(*iter)->updateText(m_playerList.back()->getName());
	std::cout << m_nameText.size() << std::endl;
}

void LobbyScreen::draw()
{
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderClear(m_renderer);
	const SDL_Rect rect{ 0, 0, w, h/10};
	SDL_SetRenderDrawColor(m_renderer, 100, 100, 100, 60);
	SDL_RenderFillRect(m_renderer, &rect);
	m_addAI->draw();
	m_start->draw();
	for (unsigned int i = 0; i < m_nameText.size(); i++)
	{
		auto const &t = m_nameText[i];
		t->draw();
		t->setY(60 + 4 * i);
	}
	SDL_RenderPresent(m_renderer);
}


void LobbyScreen::update()
{
	m_addAI->update();
	m_start->update();
}
