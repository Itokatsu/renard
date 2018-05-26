#ifndef DEF_ENEMYWAVE
#define DEF_ENEMYWAVE

#include <vector>
#include "Enemy.h"
#include "Trajectory.h"

class Trajectory;

class EnemyWave
{
  public:
	EnemyWave(unsigned int size);
	void Update(GameEngine *game, double dt);

	double *GetAdv();
	unsigned int GetSize();
	std::vector<Enemy *> GetEnemies();

  private:
	unsigned int size_;
	std::vector<Enemy *> enemies_;
	Trajectory *traj_;
	double *advancement_;
};

#endif