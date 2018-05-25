#ifndef DEF_SPRITE
#define DEF_SPRITE

#include "SDL.h"

enum Direction
{
	BAS,
	GAUCHE,
	DROITE,
	HAUT
};

struct SpriteControl {
	bool animated = true;
	Direction direction = Direction::BAS;
	float animSpeed = 100;

	int currentFrame = 0;
	int animTime = 0;
};

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
		   unsigned int maxImg);
	void NextAnim(SpriteControl *ctrl);
	void PlayAnim(SpriteControl *ctrl, float dt);

	SDL_Rect GetRect(SpriteControl *ctrl);
	SDL_Texture *GetTexture();
	int GetWidth();
	int GetHeight();

  private:
	SDL_Texture *texture_;
	int frameWidth_;
	int frameHeight_;
	//Number of animation frames
	unsigned int numFrames_;
	Direction direction_;
	float animSpeed_;

	int currentFrame_;
	int animTime_;
};

#endif