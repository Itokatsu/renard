#ifndef DEF_PROJECTILE
#define DEF_PROJECTILE

#include "SDL.h"
#include "Vec2.h"
#include "GameEngine.h"
#include "Sprite.h"
#include "Player.h"
#include "IEntity.h"

class Player;

class Projectile : public IEntity
{
  public:
	Projectile(GameEngine *game, Player *pl);

	bool IsDead();
	void Draw(GameEngine *game);
	void Update(GameEngine *game, float dt);

	// Sprite *GetSprite();
	SDL_Point GetPosition();
	Vec2f GetVelocity();
	void SetVelocity(Vec2f v);
	void SetVelocity(float velX, float velY);
	void AddVelocity(Vec2f v);
	SDL_Rect GetRect();

  private:
    Player *owner_;
	// Sprite *mySprite_;
	SDL_Point position_;
	Vec2f velocity_;
	float maxSpeed_;
};

#endif