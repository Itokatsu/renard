#include "Enemy.h"

Enemy::Enemy() : IMovable() {
	maxSpeed_ = 0.2;
	health_ = 3;
	size_ = {32, 32};
	color_ = {0x00, 0xFF, 0x00, 0xFF};
	freeBird_ = true;
}

Enemy::Enemy(double posX, double posY) : IMovable(posX, posY)
{
	maxSpeed_ = 0.2;
	health_ = 3;
	size_ = {32, 32};
	color_ = {0x00, 0xFF, 0x00, 0xFF};
	ttl_ = std::rand();
	freeBird_ = true;
}

Enemy::Enemy(Vec2d pos) : IMovable(pos)
{
	maxSpeed_ = 0.2;
	health_ = 3;
	size_ = {32, 32};
	color_ = {0x00, 0xFF, 0x00, 0xFF};
	ttl_ = std::rand();
	freeBird_ = true;
}

void Enemy::Draw(GameEngine *game)
{
	SDL_Renderer *rend = game->GetGraphicEngine()->GetRenderer();
	SDL_Rect coords = GetRect();
	SDL_Point pos = position_.ToSDLPoint();
	SDL_Point size = size_.ToSDLPoint();
	SDL_Rect rect_oeilD = {pos.x + 4, pos.y + 4, 3, 3};
	SDL_Rect rect_oeilG = {pos.x + size.x - 7, pos.y + 4, 3, 3};
	SDL_SetRenderDrawColor(rend, color_.r, color_.g, color_.b, color_.a);
	SDL_RenderFillRect(rend, &coords);
	SDL_SetRenderDrawColor(rend, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(rend, &rect_oeilD);
	SDL_RenderFillRect(rend, &rect_oeilG);
}

void Enemy::Update(GameEngine *game, double dt)
{
	IMovable::Update(game, dt);
	if (health_ <= 0 || ttl_ <= 0)
		alive_ = false;
	else
		ttl_ -= dt;
}

SDL_Color Enemy::GetColor()
{
	return color_;
}