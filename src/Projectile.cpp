#include "Projectile.h"
#include <iostream>
#include <algorithm>

Projectile::Projectile(GameEngine *game, Player *pl)
{
	// SDL_Texture *tex = game->GetDrawEngine()->GetRessource("sprite.png");
	// mySprite_ = new Sprite(tex, 96 / 3, 128 / 4, 3, 100);
	owner_ = pl;
	position_ = pl->GetPosition();
	position_.x += (pl->GetRect().w / 2);
	position_.y += -2;
	velocity_ = {.0f, -.5f};
	maxSpeed_ = 0.5;
}

bool Projectile::IsDead()
{
	// Need game !
	// if (position_.x + 6 < 0 || position_.x > game->GetWindowWidth() || position_.y + 20 < 0 || position_.y > game->GetWindowHeight())
	if (position_.x + 6 < 0 || position_.x > 640 || position_.y + 20 < 0 || position_.y > 480)
	{
		return true;
	}
	else
		return false;
}

void Projectile::Draw(GameEngine *game)
{
	SDL_Renderer *rend = game->GetGraphicEngine()->GetRenderer();
	SDL_Rect coords;
	coords = GetRect();

	SDL_SetRenderDrawColor(rend, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(rend, &coords);
}

void Projectile::Update(GameEngine *game, float dt)
{
	Vec2f cappedVel = velocity_;
	if (velocity_.Length() > maxSpeed_)
	{
		cappedVel.Truncate(maxSpeed_);
	}

	position_.x += (cappedVel.x * dt);
	position_.y += (cappedVel.y * dt);
}

// Sprite *Projectile::GetSprite()
// {
// 	return mySprite_;
// }

SDL_Rect Projectile::GetRect()
{
	SDL_Rect rect = {position_.x, position_.y, 6, 20};
	return rect;
}

SDL_Point Projectile::GetPosition()
{
	return position_;
}

Vec2f Projectile::GetVelocity()
{
	return velocity_;
}

void Projectile::SetVelocity(Vec2f v)
{
	velocity_ = v;
}

void Projectile::SetVelocity(float velX, float velY)
{
	velocity_.x = velX;
	velocity_.y = velY;
}

void Projectile::AddVelocity(Vec2f v)
{
	velocity_ += v;
}