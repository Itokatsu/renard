#include "Trajectory.h"

Trajectory::Trajectory(std::function<Vec2d(double)> f) {
	speedCoeff_ = 1;
	func_ = f;
}

void Trajectory::Advance(EnemyWave *wave, double dt) {
	double* adv = wave->GetAdv();
	unsigned int size = wave->GetSize();
	
	for(size_t i = 0; i < size; i++)
	{
		// tout en 5sec
		adv[i] += dt/5000 * speedCoeff_;
	}
}

Vec2d Trajectory::GetPoint(double advancement) {
	return func_(advancement);
}

Vec2d Trajectory::GetDirection(double prevAdvancement, double advancement) {
	Vec2d direction, prevPoint, point;
	prevPoint =  func_(prevAdvancement);
	point = func_(advancement);
	
	direction.x = point.x - prevPoint.x;
	direction.y = point.y - prevPoint.y;

	return direction;
}