#ifndef DEF_ENEMY
#define DEF_ENEMY

#include "SDL.h"
#include "Vec2.h"
#include "IMovable.h"
#include "GameEngine.h"

/* Enenmi turret -> not IMovable ! */
class Enemy : public IMovable
{
  public:
	Enemy(GameEngine *, int posX, int posY);

	void Draw(GameEngine *game);
	void Update(GameEngine *game, float dt);

	SDL_Color GetColor();

  private:
	int health_;
	SDL_Color color_;
	
	// time to live (ms)
	int ttl_;
};

#endif