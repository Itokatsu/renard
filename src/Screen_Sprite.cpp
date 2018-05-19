#include "Screen_Sprite.h"
#include <iostream>
#include "SDL.h"

Screen_Sprite Screen_Sprite::myScreen;

Screen_Sprite::Screen_Sprite()
{
}

void Screen_Sprite::Init(GameEngine *game)
{
	// texture_title = game->GetDrawEngine()->CreateTexture("../media/img/logoa2balles.png");
	game->GetDrawEngine()->LoadImage("media/img/sprite.png");
	thePlayer = new Player(game);
	std::cout << "[Sprite Screen Start]" << std::endl;
}

void Screen_Sprite::Cleanup()
{
	std::cout << "[Sprite Screen Quit]" << std::endl;
}

void Screen_Sprite::Pause()
{
}

void Screen_Sprite::Unpause()
{
}

void Screen_Sprite::HandleEvents(GameEngine *game)
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
			if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					game->Quit();
					break;
				// directions
				case SDLK_UP:
					thePlayer->GetSprite()->SetDirection(Sprite::Direction::HAUT);
					thePlayer->AddVelocity({0, -1});
					break;
				case SDLK_DOWN:
					thePlayer->GetSprite()->SetDirection(Sprite::Direction::BAS);
					thePlayer->AddVelocity({0, 1});
					break;
				case SDLK_RIGHT:
					thePlayer->GetSprite()->SetDirection(Sprite::Direction::DROITE);
					thePlayer->AddVelocity({1, 0});
					break;
				case SDLK_LEFT:
					thePlayer->GetSprite()->SetDirection(Sprite::Direction::GAUCHE);
					thePlayer->AddVelocity({-1, 0});
					break;
				}
			}
			else if (e.type == SDL_KEYUP)
			{
				switch (e.key.keysym.sym)
				{
				// Directions
				case SDLK_UP:
					thePlayer->AddVelocity({0, 1});
					break;

				case SDLK_DOWN:
					thePlayer->AddVelocity({0, -1});
					break;

				case SDLK_RIGHT:
					thePlayer->AddVelocity({-1, 0});
					break;

				case SDLK_LEFT:
					thePlayer->AddVelocity({1, 0});
					break;
				}
			}
		}
	}
}

void Screen_Sprite::Update(GameEngine *game, float dt)
{
	thePlayer->Update(game, dt);
}

void Screen_Sprite::Draw(GameEngine *game)
{
	thePlayer->Draw(game);
}

Screen_Sprite *Screen_Sprite::Instance()
{
	return &myScreen;
}