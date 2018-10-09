#pragma once
#include "../Graphics/Sprite.h"
#include "../Util/Timer.h"
class AnimatedSprite :
	public Sprite
{
public:
	AnimatedSprite(SDL_Renderer* renderer, SDL_Rect rect);
	~AnimatedSprite();
	void load(std::string path);
	void draw();
	void setFrameTime(int time);

private:
	int frame;
	int frameTime;
	SDL_Rect drawRegion;
	Timer timer;
};

