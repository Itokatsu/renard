#ifndef DEF_PROJECTILE
#define DEF_PROJECTILE

#include "SDL.h"
#include "GameEngine.h"
#include "IMovable.h"
#include "IHasCollision.h"

class Player;

class Projectile : public IMovable, public IHasCollision
{
  public:
	Projectile(IEntity *ent);

	void Draw(GameEngine *game);
	void Update(GameEngine *game, double dt);

	void CollidesWith(IHasCollision *c, SDL_Rect *collisionBox);

  private:
    IEntity *owner_;
};

#endif