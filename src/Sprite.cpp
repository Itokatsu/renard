#include "Sprite.h"

Sprite::Sprite(SDL_Texture *tex, int width, int height,
			   unsigned int maxImg)
{
	texture_ = tex;
	frameWidth_ = width;
	frameHeight_ = height;
	numFrames_ = maxImg;
}

void Sprite::NextAnim(SpriteControl *ctrl)
{
	ctrl->currentFrame = (ctrl->currentFrame + 1) % numFrames_;
}

void Sprite::PlayAnim(SpriteControl *ctrl, double dt)
{
	if (!ctrl->animated)
		return;

	ctrl->animTime += dt;
	if (ctrl->animTime > ctrl->animSpeed)
	{
		NextAnim(ctrl);
		ctrl->animTime -= ctrl->animSpeed;
	}
}

SDL_Rect Sprite::GetRect(SpriteControl *ctrl)
{
	SDL_Rect rekt = {
		ctrl->currentFrame * frameWidth_,
		ctrl->direction * frameHeight_,
		frameWidth_,
		frameHeight_};
	return rekt;
}

SDL_Texture *Sprite::GetTexture()
{
	return texture_;
}

int Sprite::GetWidth()
{
	return frameWidth_;
}

int Sprite::GetHeight()
{
	return frameHeight_;
}