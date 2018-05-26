#include "Projectile.h"

Projectile::Projectile(GameEngine *, Player *pl)
{
	// SDL_Texture *tex = game->GetDrawEngine()->GetRessource("sprite.png");
	// mySprite_ = new Sprite(tex, 96 / 3, 128 / 4, 3, 100);
	owner_ = pl;
	position_ = pl->GetPosition();
	position_.x += (pl->GetRect().w / 2);
	position_.y += -2;
	velocity_ = {.0f, -.5f};
	maxSpeed_ = 0.5;
	width_ = 6;
	height_ = 20;
	freeBird_ = true;
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
	IMovable::Update(game, dt);
	const SDL_Rect windowRect = {0, 0, game->GetWindowWidth(), game->GetWindowHeight()};
	const SDL_Rect projRect = GetRect();
	SDL_Rect intersection;
	// false if no intersection
	if (!SDL_IntersectRect(&projRect, &windowRect, &intersection)) {
		alive_ = false;
	}
}

// Sprite *Projectile::GetSprite()
// {
// 	return mySprite_;
// }