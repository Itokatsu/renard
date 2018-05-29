#ifndef DEF_IHASCOLLISION
#define DEF_IHASCOLLISION

#include "IEntity.h"

class IHasCollision : public virtual IEntity
{
  public:

	void UpdateHitBox()
	{
		hitBox_ = GetRect();
	};
	const SDL_Rect *GetHitBox() 
	{
		return &hitBox_;	
	};
	
	virtual void CollidesWith(IHasCollision *c, SDL_Rect *collisionBox) = 0;
	
  protected:
	SDL_Rect hitBox_;
};

#endif