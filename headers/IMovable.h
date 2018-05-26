#ifndef DEF_IMOVABLE
#define DEF_IMOVABLE

#include "GameEngine.h"
#include "IEntity.h"
#include "Vec2.h"
class IMovable : public virtual IEntity
{
  public:
	IMovable();
	IMovable(double posX, double posY);
	IMovable(Vec2d pos);
	IMovable(SDL_Point pos);

	void Update(GameEngine *game, double dt);

	// Position related
	void SetPosition(double x, double y);
	void SetPosition(Vec2d pos);
	void SetPosition(SDL_Point p);

	// Velocity related
	Vec2d GetVelocity();
	void SetVelocity(Vec2d v);
	void SetVelocity(double velX, double velY);
	// Operation on velocity
	void AddVelocity(Vec2d v);
	void AddVelocity(double velX, double velY);
	void MulVelocity(double m);

	// Acceleration related
	Vec2d GetAcceleration();
	void SetAcceleration(Vec2d acceleration);

  protected:
	Vec2d velocity_ = {0, 0};
	Vec2d accel_ = {0, 0};
	float maxSpeed_ = 1;
	// Can escape window boundaries
	bool freeBird_ = false;
};

#endif