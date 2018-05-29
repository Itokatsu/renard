#ifndef DEF_ENEMY
#define DEF_ENEMY

#include "GameEngine.h"
#include "IMovable.h"
#include "IHasCollision.h"

/* Enemy turret -> not IMovable ! */
class Enemy : public IMovable, public IHasCollision
{
  public:
	Enemy();
	Enemy(double posX, double posY);
	Enemy(Vec2d pos);

	void Draw(GameEngine *game);
	void Update(GameEngine *game, double dt);

	SDL_Color GetColor();

	void CollidesWith(IHasCollision *c, SDL_Rect *collisionBox);

  private:
	int health_;
	SDL_Color color_;
	
	// time to live (ms)
	int ttl_;
};

#endif