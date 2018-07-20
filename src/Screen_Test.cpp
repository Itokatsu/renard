#include "Screen_Test.h"
#include <iostream>
#include "SDL.h"
#include "math.h"
#include <iostream>

Screen_Test Screen_Test::myTest_;

Screen_Test::Screen_Test()
{
}

void Screen_Test::Init(GameEngine *game)
{
	// SDL_Color textColor = {0xBB, 0xBB, 0xBB, 0xFF};
	bullet_ = game->GetDrawEngine()->LoadSprite("media/img/bullet.png", 32, 32, 1);
	center_ = {
		static_cast<double>(game->GetWindowWidth() / 2),
		static_cast<double>(game->GetWindowHeight() / 4)};

	for (unsigned int i = 0; i < 360; i += 12)
	{
		for (unsigned int n = 0; n < 8; n++ ) {
			Bullet *b = new Bullet(center_, n*80);
			b->SetSprite(bullet_);
			Vec2d pos = center_;
			b->SetPosition(pos);
			Vec2d vel = {sin((i+n*3) * M_PI / 180), cos((i+n*3) * M_PI / 180)};
			b->SetVelocity(vel);
			//vel.Rotate(n*10);
			b->SetAcceleration(vel/2000);
			b->MulVelocity(0.3);
			projs_.push_back(b);
		}
	}

	std::cout << "[TEST Screen Start]" << std::endl;
}

void Screen_Test::Cleanup()
{
	projs_.clear();
	std::cout << "[TEST Screen Quit]" << std::endl;
}

void Screen_Test::Pause()
{
}

void Screen_Test::Unpause()
{
}

void Screen_Test::HandleEvents(GameEngine *game)
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		//Close window
		if (e.type == SDL_QUIT)
		{
			game->Quit();
		}
		else
		{
			// Key press
			if (e.type == SDL_KEYDOWN)
			{
				// ESCAPE is pressed
				if (e.key.keysym.sym == SDLK_ESCAPE)
				{
					game->PopScreen();
				}
			}
		}
	}
}

void Screen_Test::Update(GameEngine *game, double dt)
{
	for (auto &p : projs_)
	{
		if (!p->IsDead())
			p->Update(game, dt);
	}
}

void Screen_Test::Draw(GameEngine *game)
{
	for (auto &p : projs_)
	{
		if (!p->IsDead())
			p->Draw(game);
	}
}

Screen_Test *Screen_Test::Instance()
{
	return &myTest_;
}