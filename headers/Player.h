#ifndef DEF_PLAYER
#define DEF_PLAYER

#include "GameEngine.h"
#include "IMovable.h"
#include "IHasSprite.h"

class Player : public IHasSprite, public IMovable
{
  public:
	Player();
	Player(double posX, double posY);

	void Update(GameEngine *game, double dt);
	void Shoot(GameEngine *game, std::vector<IEntity*> *entities);

  private:
	int health_;
};

#endif