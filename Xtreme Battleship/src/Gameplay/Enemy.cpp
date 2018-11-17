#include "Enemy.h"


Enemy::Enemy(SDL_Renderer* renderer, const Player& pin)
	:leg(renderer), top(renderer), player(pin), renderer(renderer)
{
	leg.load("Assets/Graphics/heavy.png");
	top.load("Assets/Graphics/heavytop.png");
	x = 300;
	y = 265;
	leg.setX(x);
	top.setX(x);
	shot.w = 10;
	shot.h = 10;
	shot.x = 300;
	shot.y = 255;
	timer.start();
}


Enemy::~Enemy()
{

}


void Enemy::draw()
{
	

} 