#include "Level1.h"

Level1::Level1(SDL_Window* window)
	: GameState(window), gameWorld("Assets/Graphics/level1.json", m_renderer, m_cam, 30, 40)
{
	escape = false;
	gameWorld.load();
}

Level1::~Level1()
{
	delete m_player;
	std::cout << "Destroyed Level 1" << std::endl;
}

void Level1::update()
{

	const Uint8* keys = SDL_GetKeyboardState(NULL);

	if (keys[SDL_SCANCODE_ESCAPE])
	{
		if (!escape)
		{
			request.state = STATE_PAUSE;
			request.popCurrent = false;	
			escape = true;
		}
	}
	else if (request.state != STATE_QUIT)
	{
		escape = false;
		request.state = STATE_NONE;
	}
}

void Level1::draw()
{
	SDL_SetRenderDrawColor(m_renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(m_renderer);
	gameWorld.draw();
	SDL_RenderPresent(m_renderer);
}