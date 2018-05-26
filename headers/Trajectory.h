#ifndef DEF_TRAJECTORY
#define DEF_TRAJECTORY

#include "SDL.h"
#include "Vec2.h"
#include "EnemyWave.h"
#include <functional>

class EnemyWave;

class Trajectory
{
  public:
	Trajectory(std::function<Vec2d(double)> func);
	void Advance(EnemyWave *wave, double dt);

	Vec2d GetPoint(double advancement);

  private:
	double speedCoeff_;
	std::function<Vec2d(double)> func_;
};

#endif