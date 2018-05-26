#include "IHasSprite.h"

void IHasSprite::Draw(GameEngine *game)
{
	SDL_Renderer *rend = game->GetGraphicEngine()->GetRenderer();
	SDL_Rect spriteRect, coords;
	spriteRect = mySprite_->GetRect(&spriteCtrl_);
	coords = GetRect();

	SDL_RenderCopy(rend, mySprite_->GetTexture(), &spriteRect, &coords);
}

SDL_Rect IHasSprite::GetRect()
{
	return {
		position_.x,
		position_.y,
		mySprite_->GetWidth(),
		mySprite_->GetHeight()};
}

Sprite *IHasSprite::GetSprite() 
{
	return mySprite_;
}

void IHasSprite::SetSprite(Sprite *sprite)
{
	mySprite_ = sprite;
}

void IHasSprite::SetSprite(GameEngine *game, std::string imgPath)
{
	mySprite_ = game->GetDrawEngine()->GetSprite(imgPath);
}

void IHasSprite::SetDirection(Direction d)
{
	spriteCtrl_.direction = d;
}