#pragma once
#include <string>
#include "ButtonBase.h"
#include "../Graphics/Text.h"
class MenuButton :
	public ButtonBase
{
public:
	MenuButton(SDL_Renderer* renderer, std::string path);
	MenuButton(SDL_Renderer* renderer, std::string path, std::string text);
	~MenuButton();
	void draw() override;
	void update() override;
private:
	void onHover() override;
};

