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