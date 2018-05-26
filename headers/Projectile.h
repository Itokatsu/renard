#ifndef DEF_PROJECTILE
#define DEF_PROJECTILE

#include "SDL.h"
#include "GameEngine.h"
#include "IMovable.h"
#include "IEntity.h"

class Player;

class Projectile : public IMovable
{
  public:
	Projectile(GameEngine *game, IEntity *ent);

	void Draw(GameEngine *game);
	void Update(GameEngine *game, float dt);

  private:
    IEntity *owner_;
};

#endif