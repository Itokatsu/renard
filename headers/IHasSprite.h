#ifndef DEF_IHASSPRITE
#define DEF_IHASSPRITE

#include "GameEngine.h"
#include "IEntity.h"
#include "Sprite.h"

class IHasSprite : public virtual IEntity
{
  public:
	void Draw(GameEngine *game);

	SDL_Rect GetRect();
	Sprite *GetSprite();
	void SetSprite(Sprite *sprite);
	void SetSprite(GameEngine *game, std::string imgPath);
	void SetDirection(Direction d);

  protected:
	Sprite *mySprite_;
	SpriteControl spriteCtrl_;
};

#endif