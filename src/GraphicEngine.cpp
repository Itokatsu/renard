#include "GraphicEngine.h"
#include "SDL.h"
#include <iostream>

GraphicEngine::GraphicEngine()
{
	window_ = NULL;
	screenSurface_ = NULL;
	initialized_ = false;
	renderer_ = NULL;
}

// SDL Initialization, Window Creation, Renderer Creation
bool GraphicEngine::Init(int width, int height)
{
	bool success = true;
	// Initialize SDL
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
		// Create window
		window_ = SDL_CreateWindow("Game of the year : Hobo Edition", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
								  width, height, SDL_WINDOW_SHOWN);
		if (window_ == NULL)
		{
			std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
			success = false;
		}
		else
		{
			initialized_ = true;
			
			// Create renderer (texture usage)
			renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

			// Set alpha blending
			SDL_SetRenderDrawBlendMode(renderer_, SDL_BLENDMODE_BLEND);
			if (renderer_ == NULL)
			{
				std::cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
				success = false;
			}

			// Clear
			SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(renderer_);
		}
	}
	return success;
}

void GraphicEngine::Cleanup()
{
	if (initialized_)
	{
		SDL_FreeSurface(screenSurface_);
		screenSurface_ = NULL;

		SDL_DestroyRenderer(renderer_);
		renderer_ = NULL;

		//Destroy window
		SDL_DestroyWindow(window_);
		window_ = NULL;

		//Quit SDL subsystems
		SDL_Quit();
	}
}

SDL_Renderer *GraphicEngine::GetRenderer()
{
	return renderer_;
}