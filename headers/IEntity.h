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
	SDL_Point GetPosition()
	{
		return position_;
	};
	virtual SDL_Rect GetRect()
	{
		return {position_.x, position_.y, width_, height_};
	};
	virtual bool IsDead()
	{
		return !alive_;
	};

  protected:
	SDL_Point position_ = {0, 0}; //vec2f vs SDL_Point ?
	int width_ = 0;
	int height_ = 0;
	bool alive_ = true;
};

#endif