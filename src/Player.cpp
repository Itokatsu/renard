#include "Player.h"

Player::Player(GameEngine* game) {
	SDL_Texture* tex = game->GetDrawEngine()->GetRessource("sprite.png");
	mySprite = new Sprite(tex, 96 / 3, 128 / 4, 3, 100);
	position = {100, 100};
	velocity = {.0f, .0f};
}


void Player::Draw(GameEngine* game) {
	SDL_Renderer *rend = game->GetGraphicEngine()->GetRenderer();
	SDL_Rect spriteRect, coords;
	spriteRect = mySprite->GetRect();
	coords = GetRect();

	SDL_RenderCopy(rend, mySprite->GetTexture(), &spriteRect, &coords);
}

void Player::Update(GameEngine* game, float dt) {
	if (velocity.x != 0 || velocity.y != 0)
	{
		mySprite->PlayAnim(dt);
	}
	position.x += (velocity.x * dt * 0.5f);
	position.y += (velocity.y * dt * 0.5f);

	position.x = std::max(position.x, 0);
	position.y = std::max(position.y, 0);
	position.x = std::min(position.x, game->GetWindowWidth() - mySprite->GetWidth());
	position.y = std::min(position.y, game->GetWindowHeight() - mySprite->GetHeight());
}

Sprite* Player::GetSprite() {
	return mySprite;
}

SDL_Rect Player::GetRect() {
	SDL_Rect rect = {position.x, position.y, mySprite->GetWidth(), mySprite->GetHeight()};
	return rect;
}

SDL_Point Player::GetPosition() {
	return position;
}

vec2f Player::GetVelocity() {
	return velocity;
}

void Player::SetVelocity(vec2f v) {
	velocity = v;
}

void Player::SetVelocity(float velX, float velY) {
	velocity.x = velX;
	velocity.y = velY;
}

void Player::AddVelocity(vec2f v) {
	velocity += v;
}