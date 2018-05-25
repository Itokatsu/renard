#include "IMovable.h"

IMovable::IMovable(Vec2f pos)
{
	position_ = pos.ToSDLPoint();
}

IMovable::IMovable(int x, int y)
{
	position_ = {x, y};
}

SDL_Point IMovable::GetPosition()
{
	return position_;
}

Vec2f IMovable::GetVelocity()
{
	return velocity_;
}

Vec2f IMovable::GetAcceleration()
{
	return accel_;
}

//=============================================
//==  ALWAYS USE THIS FOR CHANGING POSITION_ ===
//=============================================
void IMovable::SetPosition(int x, int y)
{
	position_.x = x;
	position_.y = y;
	// UpdateCollisionBox();
}

void IMovable::SetPosition(Vec2f pos)
{
	position_ = pos.ToSDLPoint();
	// UpdateCollisionBox();
}

void IMovable::SetPosition(SDL_Point p)
{
	position_ = p;
	// UpdateCollisionBox();
}

void IMovable::SetVelocity(Vec2f v)
{
	velocity_ = v;
}

void IMovable::SetVelocity(float velX, float velY)
{
	velocity_.x = velX;
	velocity_.y = velY;
}

void IMovable::AddVelocity(Vec2f v)
{
	velocity_ = velocity_ + v;
}

void IMovable::AddVelocity(float velX, float velY)
{
	velocity_.x += velX;
	velocity_.y += velY;
}

void IMovable::MulVelocity(double m)
{
	velocity_ *= m;
}

void IMovable::SetAcceleration(Vec2f acceleration)
{
	accel_ = acceleration;
}

void IMovable::Update(GameEngine *game, float dt)
{
	Vec2f cappedVel = velocity_;
	if (velocity_.Length() > maxSpeed_)
	{
		cappedVel.Truncate(maxSpeed_);
	}
	position_.x += (cappedVel.x * dt);
	position_.y += (cappedVel.y * dt);

	// Check with window boundaries.
	if (!freeBird) {
		SDL_Rect rect = GetRect();
		position_.x = std::max(position_.x, 0);
		position_.y = std::max(position_.y, 0);
		position_.x = std::min(position_.x, game->GetWindowWidth() - rect.w);
		position_.y = std::min(position_.y, game->GetWindowHeight() - rect.h);
	}
}

/*
void IMovable::UpdatePosition(float dt, Match* m) 
{
	//Update Velocity
	Vec2f dAccel = accel_ * dt;
	velocity_ = velocity_ + dAccel;

	Vec2f dVelocity = velocity_ * dt;
		
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
