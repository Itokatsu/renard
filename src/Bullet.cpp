#include "Bullet.h"
#include <iostream>
#include <algorithm>
#include "Player.h"
#include "Enemy.h"

Bullet::Bullet(Vec2d pos, double delay) : IMovable(pos)
{
	size_ = {32, 32};
	maxSpeed_ = 0.5;
	freeBird_ = true;
	delay_ = delay;
	alive_ = (delay > 0);
	created_ = 0;
}

void Bullet::Update(GameEngine *game, double dt)
{
	created_ += dt;
	if (created_ < delay_) {
		return;
	}

	IMovable::Update(game, dt);
	/*const SDL_Rect windowRect = {0, 0, game->GetWindowWidth(), game->GetWindowHeight()};
	const SDL_Rect projRect = GetRect();*/
}