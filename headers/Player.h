#ifndef DEF_PLAYER
#define DEF_PLAYER

#include "GameEngine.h"
#include "IMovable.h"
#include "IHasSprite.h"

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