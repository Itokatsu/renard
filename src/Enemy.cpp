#include "Enemy.h"


Enemy::Enemy(GameEngine *, int posX, int posY) : IMovable(posX, posY)
{
	maxSpeed_ = 0.2;
	health_ = 3;
	width_ = 32;
	height_ = 32;
	color_ = {0x00, 0xFF, 0x00, 0xFF};
	ttl_ = std::rand();
}

void Enemy::Draw(GameEngine *game)
{
	SDL_Renderer *rend = game->GetGraphicEngine()->GetRenderer();
	SDL_Rect coords = GetRect();
	SDL_Rect rect_oeilD = {position_.x+4, position_.y+4, 3, 3};
	SDL_Rect rect_oeilG = {position_.x+ width_-7, position_.y+4, 3, 3};
	SDL_SetRenderDrawColor(rend, color_.r, color_.g, color_.b, color_.a);
	SDL_RenderFillRect(rend, &coords);
	SDL_SetRenderDrawColor(rend, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(rend, &rect_oeilD );
	SDL_RenderFillRect(rend, &rect_oeilG );
}

void Enemy::Update(GameEngine *, float dt)
{
	Vec2f cappedVel = velocity_;
	if (velocity_.Length() > maxSpeed_)
	{
		cappedVel.Truncate(maxSpeed_);
	}
	/*
	position_.x += (cappedVel.x * dt);
	position_.y += (cappedVel.y * dt);

	position_.x = std::max(position_.x, 0);
	position_.y = std::max(position_.y, 0);
	position_.x = std::min(position_.x, game->GetWindowWidth() - width_);
	position_.y = std::min(position_.y, game->GetWindowHeight() - height_);*/

	ttl_ -= dt;
}

bool Enemy::IsDead()
{
	return (health_ <= 0 || ttl_ <= 0);
}

SDL_Rect Enemy::GetRect()
{
	SDL_Rect rect = {position_.x, position_.y, width_, height_};
	return rect;
}


SDL_Color Enemy::GetColor()
{
	return color_;
}