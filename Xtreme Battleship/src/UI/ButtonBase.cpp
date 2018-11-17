#include "ButtonBase.h"

ButtonBase::ButtonBase(SDL_Renderer* renderer)
	:UIElement(renderer), mDown(false)
{
	onClick = [] { std::cout << "HEY IDIOT THIS BUTTON ISN'T BOUND TO ANYTHING" << std::endl; };
}

bool ButtonBase::mouseInBounds()
{
	SDL_Rect* sRect = m_sprite->getRect();
	if ((mX >= sRect->x) && (mX <= sRect->x + sRect->w) && (mY >= sRect->y) && (mY <= sRect->y + sRect->h))
	{
		return true;
	}
	else
	{
		return false;
	}
}

ButtonBase::~ButtonBase()
{
}
