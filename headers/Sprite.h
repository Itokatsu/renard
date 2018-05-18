#ifndef DEF_SPRITE
#define DEF_SPRITE

#include "SDL.h"

class Sprite
{
  public:
	enum Direction
	{
		BAS,
		GAUCHE,
		DROITE,
		HAUT
	};

	Sprite(SDL_Texture *tex, int width, int height,
		   unsigned int maxImg, float speed);
	void NextAnim();
	void PlayAnim(float dt);

	SDL_Rect GetRect();
	SDL_Texture *GetTexture();
	int GetWidth();
	int GetHeight();

	void SetSpeed(float speed);
	void SetDirection(Direction d);

  private:
	SDL_Texture *texture;
	bool animated;
	int frameWidth;
	int frameHeight;
	//Number of animation frames
	unsigned int numFrames;
	Direction direction;
	float animSpeed;

	int currentFrame;
	int animTime;
};

#endif