#include "EnemyWave.h"
#include <Vec2.h>

EnemyWave::EnemyWave(int size) {

	// (x−a)2 + (y−b)2 = r2

	float circlediv = 360/size;
	center_ = {640/2, 480/2};
	radius_ = 100;

	for(int i = 0; i < size; i++)
	{
		// angle
		Rectdouble r;
		double angle = circlediv*i;
		Vec2d v = {radius_, 0};
		v.Rotate(angle);
		Enemy *e = new Enemy(center_ + v);
		r = e->GetRectDouble();
		e->SetPosition(r.x - (r.w/2), r.y - (r.h/2) );
		enemies_.push_back(e);
	}
}

void EnemyWave::Update(GameEngine *, double dt) {
	for(auto& e : enemies_)
	{
		Rectdouble r = e->GetRectDouble();
		Vec2d p = {r.x, r.y};
		p -= center_;
		p = {p.x + (r.w/2), p.y + (r.h/2)};
		p.Rotate( dt / 50 ); // 1 deg every 50ms
		p += center_;
		p = {p.x - (r.w/2), p.y - (r.h/2)};
		e->SetPosition(p);
	}
}

void EnemyWave::Draw(GameEngine *game) {
	for(auto& e : enemies_)
	{
		e->Draw(game);
	}
}