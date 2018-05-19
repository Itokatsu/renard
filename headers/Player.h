#ifndef DEF_PLAYER
#define DEF_PLAYER

#include "SDL.h"
#include "Vec2.h"
#include "GameEngine.h"
#include "Sprite.h"

class Player
{
  public:
	Player(GameEngine *game);

	void Draw(GameEngine *game);
	void Update(GameEngine *game, float dt);

	Sprite *GetSprite();
	SDL_Point GetPosition();
	Vec2f GetVelocity();
	void SetVelocity(Vec2f v);
	void SetVelocity(float velX, float velY);
	void AddVelocity(Vec2f v);
	SDL_Rect GetRect();

  private:
	Sprite *mySprite_;
	SDL_Point position_;
	Vec2f velocity_;
	float maxSpeed_;
};

#endif