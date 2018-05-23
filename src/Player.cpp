#include "Player.h"

Player::Player(GameEngine *game)
{
	SDL_Texture *tex = game->GetDrawEngine()->GetRessource("sprite.png");
	mySprite_ = new Sprite(tex, 96 / 3, 128 / 4, 3, 100);
	position_ = {100, 100};
	velocity_ = {.0f, .0f};
	maxSpeed_ = 0.5;
	health_ = 10;
}

Player::Player(GameEngine *game, int posX, int posY)
{
	SDL_Texture *tex = game->GetDrawEngine()->GetRessource("sprite.png");
	mySprite_ = new Sprite(tex, 96 / 3, 128 / 4, 3, 100);
	position_ = {posX, posY};
	velocity_ = {.0f, .0f};
	maxSpeed_ = 0.5;
	health_ = 10;
}

void Player::Draw(GameEngine *game)
{
	SDL_Renderer *rend = game->GetGraphicEngine()->GetRenderer();
	SDL_Rect spriteRect, coords;
	spriteRect = mySprite_->GetRect();
	coords = GetRect();

	SDL_RenderCopy(rend, mySprite_->GetTexture(), &spriteRect, &coords);
}

void Player::Update(GameEngine *game, float dt)
{
	if (velocity_.x != 0 || velocity_.y != 0)
	{
		mySprite_->PlayAnim(dt);
	}

	/*Vec2f normalizedVel = velocity_;
	normalizedVel.Normalize();

	position_.x += (normalizedVel.x * dt * 0.5f);
	position_.y += (normalizedVel.y * dt * 0.5f);*/

	Vec2f cappedVel = velocity_;
	if (velocity_.Length() > maxSpeed_)
	{
		cappedVel.Truncate(maxSpeed_);
	}

	position_.x += (cappedVel.x * dt);
	position_.y += (cappedVel.y * dt);

	position_.x = std::max(position_.x, 0);
	position_.y = std::max(position_.y, 0);
	position_.x = std::min(position_.x, game->GetWindowWidth() - mySprite_->GetWidth());
	position_.y = std::min(position_.y, game->GetWindowHeight() - mySprite_->GetHeight());
}

bool Player::IsDead() 
{
	return (health_ <= 0);
}

Sprite *Player::GetSprite()
{
	return mySprite_;
}

SDL_Rect Player::GetRect()
{
	SDL_Rect rect = {	
		position_.x, 
		position_.y, 
		mySprite_->GetWidth(), 
		mySprite_->GetHeight()
	};
	return rect;
}

SDL_Point Player::GetPosition()
{
	return position_;
}

Vec2f Player::GetVelocity()
{
	return velocity_;
}

void Player::SetVelocity(Vec2f v)
{
	velocity_ = v;
}

void Player::SetVelocity(float velX, float velY)
{
	velocity_.x = velX;
	velocity_.y = velY;
}

void Player::AddVelocity(Vec2f v)
{
	velocity_ += v;
}