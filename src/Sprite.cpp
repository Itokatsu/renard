#include "Sprite.h"

Sprite::Sprite(SDL_Texture *tex, int width, int height,
			   unsigned int maxImg, float speed)
{
	texture = tex;
	frameWidth = width;
	frameHeight = height;
	numFrames = maxImg;
	animSpeed = speed;
	animated = (maxImg > 1 && speed > 0.0);

	direction = Direction::BAS;
	animTime = 0;
	currentFrame = 0;
}

void Sprite::NextAnim()
{
	currentFrame = (currentFrame + 1) % numFrames;
}

void Sprite::PlayAnim(float dt)
{
	if (!animated)
		return;
	animTime += dt;
	if (animTime > animSpeed)
	{
		NextAnim();
		animTime -= animSpeed;
	}
}

SDL_Rect Sprite::GetRect()
{
	SDL_Rect rekt = {
		currentFrame * frameWidth,
		direction * frameHeight,
		frameWidth,
		frameHeight};
	return rekt;
}

SDL_Texture *Sprite::GetTexture()
{
	return texture;
}

int Sprite::GetWidth()
{
	return frameWidth;
}

int Sprite::GetHeight()
{
	return frameHeight;
}

void Sprite::SetSpeed(float speed)
{
	animSpeed = speed;
}

void Sprite::SetDirection(Direction d)
{
	direction = d;
}