#ifndef DEF_IENTITY
#define DEF_IENTITY

#include "SDL.h"
#include "Vec2.h"
#include "GameEngine.h"

class IEntity
{
  public:

	virtual void Draw(GameEngine *game) = 0;
	virtual void Update(GameEngine *game, float dt) = 0;
	virtual bool IsDead() = 0;

	virtual SDL_Point GetPosition() = 0;
};

#endif