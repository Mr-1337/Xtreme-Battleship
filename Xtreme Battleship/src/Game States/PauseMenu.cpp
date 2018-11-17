#include "PauseMenu.h"



PauseMenu::PauseMenu(SDL_Window* window)
	:GameState(window)
{
	sprite = new Sprite(m_renderer);
	sprite->load("Assets/Graphics/shrek.png");
	quit = new MenuButton(m_renderer, "Assets/Graphics/quit.png");
	menu = new MenuButton(m_renderer, "Assets/Graphics/play.png");
	volume = new Slider(m_renderer);
	quit->setX(375);
	quit->setY(400);
	menu->setX(375);
	menu->setY(500);

	menu->onClick = [this] { request.popPrev = true; request.state = STATE_TITLE; };
	quit->onClick = [this] { request.state = STATE_QUIT; };

	escape = true;
	chunk = Mix_LoadMUS("Assets/Sound/mouth.ogg");
	request.popCurrent = true;
	Mix_PlayMusic(chunk, -1);
	volume->setX(300);
	volume->setY(200);
	timer.start();
	sprite->setX(-500);
}


PauseMenu::~PauseMenu()
{
	std::cout << "Deleting pause menu\n";
	delete volume;
	delete quit;
	delete menu;
	delete sprite;
	Mix_FreeMusic(chunk);
}


void PauseMenu::draw()
{
	SDL_SetRenderDrawColor(m_renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(m_renderer);
	sprite->draw();
	quit->draw();
	menu->draw();
	volume->draw();
	SDL_RenderPresent(m_renderer);
}


void PauseMenu::update()
{
	const Uint8* keys = SDL_GetKeyboardState(NULL);
	quit->update();
	menu->update();
	volume->update();
	if (keys[SDL_SCANCODE_ESCAPE])
	{
		if (!escape)
		{
			std::cout << "unpausing" << std::endl;
			request.state = STATE_POP;
		}
	}
	else
	{
		escape = false;
	}

}