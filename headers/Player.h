#ifndef DEF_PLAYER
#define DEF_PLAYER

#include "GameEngine.h"
#include "IMovable.h"
#include "IHasSprite.h"
#include "IHasCollision.h"
#include <iostream>

class Player : public IHasSprite,
				public IMovable, 
				public IHasCollision
{
  public:
	Player();
	Player(double posX, double posY);

	void Update(GameEngine *game, double dt);

	void SetAutofire(bool b);
	bool AutoFiring();
	void Shoot(std::vector<IEntity*> *entities);

	void CollidesWith(IHasCollision *c, SDL_Rect *collisionBox);

  private:
	int health_;
	
	bool autofire_ = false;
	int fireRate_;
	int lastShot_;
};

#endif