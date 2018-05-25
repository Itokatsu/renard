#include "Screen_Pause.h"

#include <iostream>
#include "SDL.h"

Screen_Pause Screen_Pause::myPause_;

Screen_Pause::Screen_Pause()
{
	displayBG_ = true;
}

void Screen_Pause::Init(GameEngine *)
{
	std::cout << "[Pause Screen Start]" << std::endl;
}

void Screen_Pause::Cleanup()
{
	std::cout << "[Pause Screen Quit]" << std::endl;
}

void Screen_Pause::Pause() {}

void Screen_Pause::Unpause() {}

void Screen_Pause::HandleEvents(GameEngine *game)
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		// User requests quit
		if (e.type == SDL_QUIT)
		{
			game->Quit();
		}
		else
		{
			// Unpause if P is pressed
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_p)
				{
					game->PopScreen();
				}
			}
		}
	}
}

void Screen_Pause::Update(GameEngine *, float) {}

void Screen_Pause::Draw(GameEngine *game)
{
	SDL_Renderer *rend = game->GetGraphicEngine()->GetRenderer();
	SDL_SetRenderDrawColor(rend, 0x00, 0x00, 0x00, 0xB7);
	SDL_Rect filter = {0, 0, 640, 480};
	SDL_RenderFillRect(game->GetGraphicEngine()->GetRenderer(), &filter);
}

Screen_Pause *Screen_Pause::Instance()
{
	return &myPause_;
}