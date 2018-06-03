#include "Screen_Test.h"
#include <iostream>
#include "SDL.h"

Screen_Test Screen_Test::myTest_;

Screen_Test::Screen_Test()
{
}

void Screen_Test::Init(GameEngine *game)
{
	// SDL_Color textColor = {0xBB, 0xBB, 0xBB, 0xFF};
	texturePng_ = game->GetDrawEngine()->LoadImage("media/img/kyo.png");
	std::cout << "[TEST Screen Start]" << std::endl;
}

void Screen_Test::Cleanup()
{
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

void Screen_Test::Update(GameEngine *, double)
{
}

void Screen_Test::Draw(GameEngine *game)
{
}

Screen_Test *Screen_Test::Instance()
{
	return &myTest_;
}