#ifndef DEF_IENTITY
#define DEF_IENTITY

#include "GameEngine.h"
#include "Vec2.h"

struct Rectdouble {
	double x;
	double y;
	double w;
	double h;
};

class IEntity
{
  public:
	virtual void Draw(GameEngine *game) = 0;
	virtual void Update(GameEngine *game, double dt) = 0;
	Vec2d GetPosition()
	{
		return position_;
	};
	Vec2d GetSize()
	{
		return size_;
	}

	Rectdouble GetRectDouble() {
		return {position_.x,
			position_.y,
			size_.x,
			size_.y};
	}

	virtual SDL_Rect GetRect()
	{
		SDL_Point pos, size;
		pos = position_.ToSDLPoint();
		size = size_.ToSDLPoint();
		return {pos.x, pos.y, size.x, size.y};
	};
	virtual bool IsDead()
	{
		return !alive_;
	};

  protected:
	Vec2d position_ = {0, 0}; //vec2f vs SDL_Point ?
	Vec2d size_ = {0, 0};
	bool alive_ = true;
};

#endif