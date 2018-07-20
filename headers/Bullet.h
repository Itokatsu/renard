#ifndef DEF_BULLET
#define DEF_BULLET

#include "SDL.h"
#include "GameEngine.h"
#include "IMovable.h"
#include "IHasSprite.h"

class Bullet : public IMovable, public IHasSprite
{
  public:
	Bullet(Vec2d pos, double delay);

	void Update(GameEngine *game, double dt);

  private:
	double created_;
	double delay_;

};

#endif