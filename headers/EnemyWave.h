#ifndef DEF_ENEMYWAVE
#define DEF_ENEMYWAVE

#include <vector>
#include "Enemy.h"

// circle wave
class EnemyWave
{
  public:
	EnemyWave(int size);
	void Update(GameEngine *game, double dt);
	void Draw(GameEngine *game);

  protected:
	std::vector<Enemy *> enemies_;
	Vec2d center_;
	float radius_;
};

#endif