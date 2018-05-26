#include "Player.h"
#include "Projectile.h"

Player::Player() : IMovable()
{
	health_ = 10;
}

Player::Player(double posX, double posY) : IMovable(posX, posY)
{
	health_ = 10;
}

void Player::Update(GameEngine *game, double dt)
{
	IMovable::Update(game, dt);
	if (health_ <= 0) 
	{
		alive_ = false;
	}
	if (velocity_.x != 0 || velocity_.y != 0)
	{
		mySprite_->PlayAnim(&spriteCtrl_, dt);
	}
}

void Player::Shoot(GameEngine *game, std::vector<IEntity*> *entities)
{
	(*entities).push_back(new Projectile(game, this));
}