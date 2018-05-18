#include "GraphicEngine.h"
#include "SDL.h"
#include <iostream>

GraphicEngine::GraphicEngine()
{
	window = NULL;
	screenSurface = NULL;
	initialized = false;
	renderer = NULL;
}

bool GraphicEngine::Init(int width, int height)
{
	bool success = true;
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "SDL could not initialize! SDL_Error:" << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			std::cerr << "Warning: Linear texture filtering not enabled!" << std::endl;
			success = false;
		}
		//Create window
		window = SDL_CreateWindow("Game of the year : Hobo Edition", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
								  width, height, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
			success = false;
		}
		else
		{
			initialized = true;
			// for surface usage
			/*screenSurface = SDL_GetWindowSurface(window);*/

			// creating renderer (texture usage)
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			// renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
			SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
			if (renderer == NULL)
			{
				std::cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
				success = false;
			}
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(renderer);
		}
	}
	return success;
}

void GraphicEngine::Cleanup()
{
	if (initialized)
	{
		SDL_FreeSurface(screenSurface);
		screenSurface = NULL;

		SDL_DestroyRenderer(renderer);
		renderer = NULL;

		//Destroy window
		SDL_DestroyWindow(window);
		window = NULL;

		//Quit SDL subsystems
		SDL_Quit();
	}
}

SDL_Renderer *GraphicEngine::GetRenderer()
{
	return renderer;
}