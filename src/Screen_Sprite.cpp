#include "Screen_Sprite.h"
#include <iostream>
#include "SDL.h"

#include "Player.h"
#include "Enemy.h"
#include "Screen_Pause.h"

Screen_Sprite Screen_Sprite::myScreen_;

Screen_Sprite::Screen_Sprite() {}

void Screen_Sprite::Init(GameEngine *game)
{
	game->GetDrawEngine()->LoadSprite("media/img/sprite.png", 96 / 3, 128 / 4, 3);
	
	thePlayer_ = new Player(game, game->GetWindowWidth() / 2 - 20, game->GetWindowHeight() - 100);
	thePlayer_->SetSprite(game, "sprite.png");

	for (int i = 0; i < 5; i++)
	{
		entities_.push_back(new Enemy(game, (1 + i) * 100, 150));
	}

	entities_.push_back(thePlayer_);

	std::cout << "[Sprite Screen Start]" << std::endl;
}

void Screen_Sprite::Cleanup()
{
	// entities_.clear();
	std::cout << "[Sprite Screen Quit]" << std::endl;
}

void Screen_Sprite::Pause()
{
	IGameScreen::Pause();
}

void Screen_Sprite::Unpause()
{
	IGameScreen::Unpause();
	thePlayer_->SetVelocity({0.f, 0.f});
	float baseSpd = 1;
	//SDL_PumpEvents();
	const Uint8 *keyStates = SDL_GetKeyboardState(NULL);
	if (keyStates[SDL_SCANCODE_UP])
	{
		thePlayer_->AddVelocity({0.f, -baseSpd});
	}
	if (keyStates[SDL_SCANCODE_DOWN])
	{
		thePlayer_->AddVelocity({0.f, baseSpd});
	}
	if (keyStates[SDL_SCANCODE_LEFT])
	{
		thePlayer_->AddVelocity({-baseSpd, 0.f});
	}
	if (keyStates[SDL_SCANCODE_RIGHT])
	{
		thePlayer_->AddVelocity({baseSpd, 0.f});
	}
}

void Screen_Sprite::HandleEvents(GameEngine *game)
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		// Close window
		if (e.type == SDL_QUIT)
		{
			game->Quit();
		}
		else
		{
			// Key pressed
			if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					game->PopScreen();
					break;
				// P for Pause
				case SDLK_p:
					game->PushScreen(Screen_Pause::Instance());
					break;
				// directions
				case SDLK_UP:
					thePlayer_->SetDirection(Direction::HAUT);
					thePlayer_->AddVelocity({0, -1});
					break;
				case SDLK_DOWN:
					thePlayer_->SetDirection(Direction::BAS);
					thePlayer_->AddVelocity({0, 1});
					break;
				case SDLK_RIGHT:
					thePlayer_->SetDirection(Direction::DROITE);
					thePlayer_->AddVelocity({1, 0});
					break;
				case SDLK_LEFT:
					thePlayer_->SetDirection(Direction::GAUCHE);
					thePlayer_->AddVelocity({-1, 0});
					break;
				}
			}
			// Key released
			else if (e.type == SDL_KEYUP)
			{
				switch (e.key.keysym.sym)
				{
				// Directions
				case SDLK_UP:
					thePlayer_->AddVelocity({0, 1});
					break;

				case SDLK_DOWN:
					thePlayer_->AddVelocity({0, -1});
					break;

				case SDLK_RIGHT:
					thePlayer_->AddVelocity({-1, 0});
					break;

				case SDLK_LEFT:
					thePlayer_->AddVelocity({1, 0});
					break;
				}
			}
		}
	}
}

void Screen_Sprite::Update(GameEngine *game, float dt)
{
	for (auto &e : entities_)
	{
		if (!e->IsDead())
			e->Update(game, dt);
	}
}

void Screen_Sprite::Draw(GameEngine *game)
{
	for (auto &e : entities_)
	{
		if (!e->IsDead())
			e->Draw(game);
	}
}

Screen_Sprite *Screen_Sprite::Instance()
{
	return &myScreen_;
}