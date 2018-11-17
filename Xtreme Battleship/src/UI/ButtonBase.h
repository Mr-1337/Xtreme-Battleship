#pragma once
#include "../Graphics/Sprite.h"
#include "UIElement.h"
#include <functional>
class ButtonBase
	:public UIElement
{
public:
	ButtonBase(SDL_Renderer* renderer);
	std::function<void(void)> onClick;
	virtual ~ButtonBase()=0;	

protected:
	
	virtual void onHover() = 0;
	bool mouseInBounds();
	int mX;
	int mY;

	bool mDown;
	
};

