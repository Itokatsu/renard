#include "Player.h"
#include "Projectile.h"
#include "Enemy.h"

Player::Player() : IMovable()
{
	health_ = 10;
	fireRate_ = 200;
	lastShot_ = 200;
}

Player::Player(double posX, double posY) : IMovable(posX, posY)
{
	health_ = 10;
	fireRate_ = 200;
	lastShot_ = 200;
}

void Player::Update(GameEngine *game, double dt)
{
	IMovable::Update(game, dt);
	lastShot_ += dt;
	if (health_ <= 0) 
	{
		alive_ = false;
	}
	if (velocity_.x != 0 || velocity_.y != 0)
	{
		mySprite_->PlayAnim(&spriteCtrl_, dt);
	}
	UpdateHitBox();
}

void Player::SetAutofire(bool b) 
{
	autofire_ = b;
}

bool Player::AutoFiring()
{
	return autofire_;
}

void Player::Shoot(std::vector<IEntity*> *entities)
{
	if (lastShot_ < fireRate_)
		return;
	entities->push_back(new Projectile(this));
	lastShot_ = 0;
}

void Player::CollidesWith(IHasCollision *c, SDL_Rect *collisionBox)
{
	Projectile *proj = dynamic_cast<Projectile*>(c);
	if (proj)
	{
		std::cout << "Player hit a projectile." << std::endl;
		return;
	}

	Enemy *e = dynamic_cast<Enemy*>(c);
	if (e)
	{
		std::cout << "Player hit an enemy." << std::endl;
		return;
	}

}