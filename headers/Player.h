#ifndef DEF_PLAYER
#define DEF_PLAYER

#include "SDL.h"
#include "IMovable.h"
#include "IHasSprite.h"
#include "GameEngine.h"

class Player : public IHasSprite, public IMovable
{
  public:
	Player(GameEngine *game);
	Player(GameEngine *game, int posX, int posY);

	void Update(GameEngine *game, float dt);
	void Shoot(GameEngine *game, std::vector<IEntity*> *entities);

  private:
	int health_;
};

#endif