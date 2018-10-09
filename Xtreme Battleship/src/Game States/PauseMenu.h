#pragma once
#include "GameState.h"
#include "../Util/Timer.h"
#include "../UI/MenuButton.h"
#include "../UI/Slider.h"
#include "../Core/GameSettings.h"
#include <SDL_mixer.h>
class PauseMenu :
	public GameState
{
public:
	PauseMenu(SDL_Window* window);
	void update() override;
	void draw() override;
	~PauseMenu();
private:
	Sprite* sprite;
	Timer timer;
	Mix_Music* chunk;
	MenuButton* quit;
	MenuButton* menu;
	Slider* volume;
	bool escape;
};

