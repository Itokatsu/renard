#ifndef DEF_PROJECTILE
#define DEF_PROJECTILE

#include "SDL.h"
#include "GameEngine.h"
#include "IMovable.h"
#include "Player.h"

class Projectile : public IMovable
{
  public:
	Projectile(GameEngine *game, Player *pl);

	void Draw(GameEngine *game);
	void Update(GameEngine *game, double dt);

  private:
    Player *owner_;
};

#endif