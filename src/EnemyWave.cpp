#include "EnemyWave.h"
#include <Vec2.h>
#include <cmath>
#include <algorithm>
#include <iterator>

EnemyWave::EnemyWave(unsigned int size)
{
	std::function<Vec2d(double)> linearBidon = [](double d) 
	{
		Vec2d v = {840*d - 100, 480/2};
		return v;
	};
	// std::function<Vec2d(double)> cercle = [](double d) {
	// 	Vec2d center = {640 / 2, 480 / 2};
	// 	double radius = 120;
	// 	Vec2d v = {center.x + radius * cos(d * 2 * M_PI), center.y + radius * sin(d * 2 * M_PI)};
	// 	return v;
	// };

	// std::function<Vec2d(double)> star = [](double d)
	// {
	// 	// Only keeps decimal part of the number
	// 	d = d - (long)d;

	// 	Vec2d center = {640/2, 480/2};
	// 	Vec2d topleft = center;
	// 	topleft.x -= 180;
	// 	topleft.y -= 180;

	// 	Vec2d v;
	// 	if(d < 0.2)
	// 		v = { topleft.x + (d*5)*320, topleft.y + 160};
	// 	else if (d < 0.4)
	// 		v = { (topleft.x + 320) - ((d - 0.2) * 5 * 280), (topleft.y + 160) + ((d - 0.2) * 5 * 240) };
	// 	else if (d < 0.6)
	// 		v = { (topleft.x + 40) + ((d - 0.4) * 5 * 120), (topleft.y + 400) - ((d - 0.4) * 5 * 400) };
	// 	else if (d < 0.8)
	// 		v = { (topleft.x + 160) + ((d - 0.6) * 5 * 120), topleft.y + ((d - 0.6) * 5 * 400) };
	// 	else
	// 		v = { (topleft.x + 280) - ((d - 0.8) * 5 * 280), (topleft.y + 400) - ((d - 0.8) * 5 * 240)};
	// 	return v;
	// };

	size_ = size;
	advancement_ = new double[size_];
	traj_ = new Trajectory(linearBidon);

	for (size_t i = 0; i < size_; i++)
	{
		Enemy *e = new Enemy(0, 0);
		advancement_[i] = i / static_cast<double>(size_);
		Vec2d start = traj_->GetPoint(advancement_[i]);
		e->CenterOn(start);
		enemies_.push_back(e);
	}
}

void EnemyWave::Update(GameEngine *game, double dt)
{
	double prevAdv[size_];
	for(size_t i = 0; i < size_; i++)
		prevAdv[i] = advancement_[i];
	
	traj_->Advance(this, dt);
	for (size_t i = 0; i < size_; i++)
	{
		Vec2d d = traj_->GetDirection(prevAdv[i], advancement_[i]);
		d = d / dt;
		enemies_[i]->SetVelocity(d);

		// Vec2d p = traj_->GetPoint(advancement_[i]);
		// enemies_[i]->CenterOn(p);
		// enemies_[i]->Update(game, dt);
	}
}

double *EnemyWave::GetAdv()
{
	return advancement_;
}

unsigned int EnemyWave::GetSize()
{
	return size_;
}

std::vector<Enemy *> EnemyWave::GetEnemies()
{
	return enemies_;
}