#include "EnemyWave.h"
#include <Vec2.h>
#include <cmath>

EnemyWave::EnemyWave(unsigned int size) {
	/*std::function<Vec2d(double)> linearBidon = [](double d) 
	{
		Vec2d v = {840*d - 100, 480/2};
		return v;
	};*/
	std::function<Vec2d(double)> cercle = [](double d) 
	{
		Vec2d center = {640/2, 480/2};
		double radius = 120;
		Vec2d v = {center.x + radius*cos(d*2*M_PI), center.y + radius*sin(d*2*M_PI)};
		return v;
	};
	size_ = size;
	advancement_ = new double[size];
	traj_ = new Trajectory(cercle);

	for(size_t i = 0; i < size_; i++)
	{
		Enemy *e = new Enemy(0, 0);
		advancement_[i] = i/static_cast<double>(size_);
		Vec2d start = traj_->GetPoint(advancement_[i]);
		e->CenterOn(start);
		enemies_.push_back(e);
	}
}

void EnemyWave::Update(GameEngine *game, double dt) {
	traj_->Advance(this, dt);
	for(size_t i = 0; i < size_; i++)
	{
		Vec2d p = traj_->GetPoint(advancement_[i]);
		enemies_[i]->CenterOn(p);
		enemies_[i]->Update(game, dt);
	}
}

double *EnemyWave::GetAdv() {
	return advancement_;
}

unsigned int EnemyWave::GetSize() {
	return size_;
}

std::vector<Enemy*> EnemyWave::GetEnemies() {
	 return enemies_;
 }