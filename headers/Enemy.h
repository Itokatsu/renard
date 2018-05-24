#ifndef DEF_ENEMY
#define DEF_ENEMY

#include "SDL.h"
#include "IEntity.h"
#include "IMovable.h"
#include "Vec2.h"
#include "GameEngine.h"
#include "Sprite.h"

class Enemy : public IEntity, public IMovable
{
  public:
	Enemy(GameEngine *, int posX, int posY);

	void Draw(GameEngine *game);
	void Update(GameEngine *game, float dt);

	bool IsDead();
	SDL_Rect GetRect();
	SDL_Color GetColor();

  private:
	int width_;
	int height_;
	int health_;
	SDL_Color color_;
	// time to live (ms)
	int ttl_;

};

#endif