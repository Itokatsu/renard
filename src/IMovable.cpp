#include "IMovable.h"

IMovable::IMovable() {}

IMovable::IMovable(Vec2d pos)
{
	position_ = pos;
}

IMovable::IMovable(double x, double y)
{
	position_ = {x, y};
}

Vec2d IMovable::GetVelocity()
{
	return velocity_;
}

Vec2d IMovable::GetAcceleration()
{
	return accel_;
}

//=============================================
//==  ALWAYS USE THIS FOR CHANGING POSITION_ ===
//=============================================

void IMovable::SetPosition(double x, double y)
{
	position_.x = x;
	position_.y = y;
	// UpdateCollisionBox();
}

void IMovable::SetPosition(Vec2d pos)
{
	position_ = pos;
	// UpdateCollisionBox();
}

void IMovable::SetPosition(SDL_Point p)
{
	position_.x = static_cast<double>(p.x);
	position_.y = static_cast<double>(p.y);
	// UpdateCollisionBox();
}

void IMovable::SetVelocity(double velX, double velY)
{
	velocity_.x = velX;
	velocity_.y = velY;
}

void IMovable::SetVelocity(Vec2d v)
{
	velocity_ = v;
}

void IMovable::AddVelocity(Vec2d v)
{
	velocity_ = velocity_ + v;
}

void IMovable::AddVelocity(double velX, double velY)
{
	velocity_.x += velX;
	velocity_.y += velY;
}

void IMovable::MulVelocity(double m)
{
	velocity_ *= m;
}

void IMovable::SetAcceleration(Vec2d acceleration)
{
	accel_ = acceleration;
}

void IMovable::Update(GameEngine *game, double dt)
{
	Vec2d cappedVel = velocity_;
	if (velocity_.Length() > maxSpeed_)
	{
		cappedVel.Truncate(maxSpeed_);
	}
	
	// SetPosition (cappedVel * dt + position_)
	position_.x += (cappedVel.x * dt);
	position_.y += (cappedVel.y * dt);

	// Check with window boundaries.
	if (!freeBird_)
	{
		SDL_Rect rect = GetRect();
		position_.x = std::max(position_.x, 0.0);
		position_.y = std::max(position_.y, 0.0);
		position_.x = std::min(position_.x, static_cast<double>(game->GetWindowWidth() - rect.w));
		position_.y = std::min(position_.y, static_cast<double>(game->GetWindowHeight() - rect.h));
	}
}

/*
void IMovable::UpdatePosition(float dt, Match* m) 
{
	//Update Velocity
	Vec2d dAccel = accel_ * dt;
	velocity_ = velocity_ + dAccel;

	Vec2d dVelocity = velocity_ * dt;
		
	//escape recursivity
	if ( dVelocity.length() <= 1){
		SetPos(position_ + dVelocity);
		//check & handle collision here
		m->ChkCollision(this);
	}
	else {
		//time that passed during the travel of a normalized vect
		float t_norm = dt / dVelocity.length();
		SetPos(position_ + dVelocity.normalize());
		//check & handle collision here
		m->ChkCollision(this);

		UpdatePosition_(dT-t_norm, m);
	}
}*/
