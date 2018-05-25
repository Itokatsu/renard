#ifndef DEF_PROJECTILE
#define DEF_PROJECTILE

#include "SDL.h"
#include "Vec2.h"
#include "GameEngine.h"
#include "Sprite.h"
#include "Player.h"
#include "IEntity.h"

class Player;

class Projectile : public IMovable
{
  public:
	Projectile(GameEngine *game, Player *pl);

	void Draw(GameEngine *game);
	void Update(GameEngine *game, float dt);

	// Sprite *GetSprite();

  private:
    Player *owner_;
	// Sprite *mySprite_;
};

#endif