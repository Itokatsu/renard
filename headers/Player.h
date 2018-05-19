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
	vec2f GetVelocity();
	void SetVelocity(vec2f v);
	void SetVelocity(float velX, float velY);
	void AddVelocity(vec2f v);
	SDL_Rect GetRect();

  private:
	Sprite *mySprite;
	SDL_Point position;
	vec2f velocity;
};

#endif