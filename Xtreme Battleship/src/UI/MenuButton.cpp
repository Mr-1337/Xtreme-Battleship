#include "MenuButton.h"

MenuButton::MenuButton(SDL_Renderer* renderer, std::string path):
	ButtonBase(renderer)
{
	m_sprite = new Sprite(renderer);
	m_sprite->load(path);
}


MenuButton::MenuButton(SDL_Renderer* renderer, std::string path, std::string text):
	ButtonBase(renderer)
{
	m_sprite = new Text(m_renderer, text);
	dynamic_cast<Text*>(m_sprite)->load(path, 18);
}

MenuButton::~MenuButton()
{
	delete m_sprite;
}


void MenuButton::onHover()
{
	SDL_Rect* rect = m_sprite->getRect();
	//m_sprite->setWidthHeight(70, 50);
	//m_sprite->setX(x-10);
	//m_sprite->setY(y-10);
}

void MenuButton::update()
{
	auto button = SDL_GetMouseState(&mX, &mY);
	if (mouseInBounds())
	{
		onHover();
		if (button == SDL_BUTTON_LMASK)
		{
			onClick();
		}
	}
	else
	{
		//m_sprite->setWidthHeight(50, 30);
		//m_sprite->setX(x);
		//m_sprite->setY(y);
	}
}

void MenuButton::draw()
{
	m_sprite->draw();
}
