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
	texture_png = game->GetDrawEngine()->LoadImage("media/img/sprite.png");
	mySprite = new Sprite(texture_png, 96 / 3, 128 / 4, 3, 100);

	sprite_xspeed = 0;
	sprite_yspeed = 0;
	sprite_x = 100;
	sprite_y = 100;
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
				// ESCAPE is pressed
				if (e.key.keysym.sym == SDLK_ESCAPE)
				{
					game->Quit();
				}

				// Directions
				if (e.key.keysym.sym == SDLK_UP)
				{
					mySprite->SetDirection(Sprite::Direction::HAUT);
					sprite_yspeed -= 1;
				}
				if (e.key.keysym.sym == SDLK_DOWN)
				{
					mySprite->SetDirection(Sprite::Direction::BAS);
					sprite_yspeed += 1;
				}
				if (e.key.keysym.sym == SDLK_RIGHT)
				{
					mySprite->SetDirection(Sprite::Direction::DROITE);
					sprite_xspeed += 1;
				}
				if (e.key.keysym.sym == SDLK_LEFT)
				{
					mySprite->SetDirection(Sprite::Direction::GAUCHE);
					sprite_xspeed -= 1;
				}
			}
			else if (e.type == SDL_KEYUP)
			{
				// Directions
				if (e.key.keysym.sym == SDLK_UP)
				{
					sprite_yspeed += 1;
				}
				if (e.key.keysym.sym == SDLK_DOWN)
				{
					sprite_yspeed -= 1;
				}
				if (e.key.keysym.sym == SDLK_RIGHT)
				{
					sprite_xspeed -= 1;
				}
				if (e.key.keysym.sym == SDLK_LEFT)
				{
					sprite_xspeed += 1;
				}
			}
		}
	}
}

void Screen_Sprite::Update(GameEngine *game, float dt)
{
	if (sprite_xspeed != 0 || sprite_yspeed != 0)
	{
		mySprite->PlayAnim(dt);
	}
	sprite_x += (sprite_xspeed * dt * 0.5);
	sprite_y += (sprite_yspeed * dt * 0.5);

	sprite_x = std::max(sprite_x, 0);
	sprite_y = std::max(sprite_y, 0);
	sprite_x = std::min(sprite_x, game->GetWindowWidth() - mySprite->GetWidth());
	sprite_y = std::min(sprite_y, game->GetWindowHeight() - mySprite->GetHeight());
}

void Screen_Sprite::Draw(GameEngine *game)
{
	SDL_Renderer *rend = game->GetGraphicEngine()->GetRenderer();
	SDL_Rect coord, spriteRect;
	coord = {sprite_x, sprite_y, mySprite->GetWidth(), mySprite->GetHeight()};
	spriteRect = mySprite->GetRect();

	SDL_RenderCopy(rend, texture_png, &spriteRect, &coord);
}

Screen_Sprite *Screen_Sprite::Instance()
{
	return &myScreen;
}