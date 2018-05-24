#ifndef DEF_PLAYER
#define DEF_PLAYER

#include "SDL.h"
#include "IEntity.h"
#include "IMovable.h"
#include "Vec2.h"
#include "GameEngine.h"
#include "Sprite.h"
#include <string>

class Player : public IMovable, public IEntity
{
  public:
	Player(GameEngine *game);
	Player(GameEngine *game, int posX, int posY);

	void Draw(GameEngine *game);
	void Update(GameEngine *game, float dt);

	bool IsDead();
	Sprite *GetSprite();
	void SetSprite(Sprite *sprite);
	void SetSprite(GameEngine *game, std::string imgPath);
	void SetDirection(Direction d);
	SDL_Rect GetRect();

  private:
	Sprite *mySprite_;
	SpriteControl sprCtrl_;
	int health_;
};

#endif