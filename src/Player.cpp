#include "Player.h"
#include "IMovable.h"

Player::Player(GameEngine *) : IMovable()
{
	health_ = 10;
}

Player::Player(GameEngine *, int posX, int posY) : IMovable(posX, posY)
{
	health_ = 10;
}

void Player::Draw(GameEngine *game)
{
	SDL_Renderer *rend = game->GetGraphicEngine()->GetRenderer();
	SDL_Rect spriteRect, coords;
	spriteRect = mySprite_->GetRect(&sprCtrl_);
	coords = GetRect();

	SDL_RenderCopy(rend, mySprite_->GetTexture(), &spriteRect, &coords);
}

void Player::Update(GameEngine *game, float dt)
{
	IMovable::Update(game, dt);
	if (health_ <= 0) 
	{
		alive_ = false;
	}
	if (velocity_.x != 0 || velocity_.y != 0)
	{
		mySprite_->PlayAnim(&sprCtrl_, dt);
	}
}

Sprite *Player::GetSprite()
{
	return mySprite_;
}

void Player::SetSprite(Sprite *sprite)
{
	mySprite_ = sprite;
}

void Player::SetSprite(GameEngine *game, std::string imgPath)
{
	mySprite_ = game->GetDrawEngine()->GetSprite(imgPath);
}

void Player::SetDirection(Direction d)
{
	sprCtrl_.direction = d;
}

SDL_Rect Player::GetRect()
{
	SDL_Rect rect = {
		position_.x,
		position_.y,
		mySprite_->GetWidth(),
		mySprite_->GetHeight()};
	return rect;
}