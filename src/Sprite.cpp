#include "Sprite.h"

Sprite::Sprite(SDL_Texture *tex, int width, int height,
			   unsigned int maxImg, float speed)
{
	texture_ = tex;
	frameWidth_ = width;
	frameHeight_ = height;
	numFrames_ = maxImg;
	animSpeed_ = speed;
	animated_ = (maxImg > 1 && speed > 0.0);

	direction_ = Direction::BAS;
	animTime_ = 0;
	currentFrame_ = 0;
}

void Sprite::NextAnim()
{
	currentFrame_ = (currentFrame_ + 1) % numFrames_;
}

void Sprite::PlayAnim(float dt)
{
	if (!animated_)
		return;
	animTime_ += dt;
	if (animTime_ > animSpeed_)
	{
		NextAnim();
		animTime_ -= animSpeed_;
	}
}

SDL_Rect Sprite::GetRect()
{
	SDL_Rect rekt = {
		currentFrame_ * frameWidth_,
		direction_ * frameHeight_,
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

void Sprite::SetSpeed(float speed)
{
	animSpeed_ = speed;
}

void Sprite::SetDirection(Direction d)
{
	direction_ = d;
}