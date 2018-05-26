#ifndef DEF_PROJECTILE
#define DEF_PROJECTILE

#include "SDL.h"
#include "GameEngine.h"
#include "Player.h"
#include "IMovable.h"

class Projectile : public IMovable
{
  public:
	Projectile(GameEngine *game, Player *pl);

	void Draw(GameEngine *game);
	void Update(GameEngine *game, float dt);

  private:
    Player *owner_;
};

#endif