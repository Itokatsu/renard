#ifndef DEF_IMOVABLE
#define DEF_IMOVABLE

#include "SDL.h"
#include "Vec2.h"
#include "IEntity.h"
#include "GameEngine.h"

class IMovable : public IEntity
{
  public:
	IMovable();
	IMovable(int posX, int posY);
	IMovable(Vec2f pos);
	IMovable(SDL_Point pos);

	void Update(GameEngine *game, float dt);

	// Position related
	void SetPosition(int x, int y);
	void SetPosition(Vec2f pos);
	void SetPosition(SDL_Point p);

	// Velocity related
	Vec2f GetVelocity();
	void SetVelocity(Vec2f v);
	void SetVelocity(float velX, float velY);
	// Operation on velocity
	void AddVelocity(Vec2f v);
	void AddVelocity(float velX, float velY);
	void MulVelocity(double m);

	// Acceleration related
	Vec2f GetAcceleration();
	void SetAcceleration(Vec2f acceleration);

  protected:
	Vec2f velocity_ = {0.f, 0.f};
	Vec2f accel_ = {0.f, 0.f};
	float maxSpeed_ = 1;
	// Can escape window boundaries
	bool freeBird_ = false;
};

#endif