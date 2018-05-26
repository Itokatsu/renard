#include "Projectile.h"
#include <iostream>
#include <algorithm>
#include "Player.h"
#include "Enemy.h"

Projectile::Projectile(GameEngine *, IEntity *ent) : IMovable()
{
	owner_ = ent;
	position_ = ent->GetPosition();
	position_.x += (ent->GetRect().w / 2);
	position_.y += -2;
	size_ = {6, 20};
	velocity_ = {.0, -.5};
	maxSpeed_ = 0.5;
	freeBird_ = true;
	
	// If shot by Player
	if (dynamic_cast<Player*>(ent))
	{
		MulVelocity(1.);
	}
	// If shot by enemies
	else if (dynamic_cast<Enemy*>(ent))
	{
		MulVelocity(-1.);
	}
}

void Projectile::Draw(GameEngine *game)
{
	SDL_Renderer *rend = game->GetGraphicEngine()->GetRenderer();
	SDL_Rect coords;
	coords = GetRect();

	SDL_SetRenderDrawColor(rend, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(rend, &coords);
}

void Projectile::Update(GameEngine *game,double dt)
{
	IMovable::Update(game, dt);
	const SDL_Rect windowRect = {0, 0, game->GetWindowWidth(), game->GetWindowHeight()};
	const SDL_Rect projRect = GetRect();
	SDL_Rect intersection;
	// false if no intersection
	if (!SDL_IntersectRect(&projRect, &windowRect, &intersection)) {
		alive_ = false;
	}
}