#ifndef DEF_GRAPHENGINE
#define DEF_GRAPHENGINE

#include "SDL.h"

class GraphicEngine 
{
	public:
		GraphicEngine();
		bool Init();
		void Cleanup();
		SDL_Renderer* GetRenderer();
		const int SCREEN_WIDTH = 640;
		const int SCREEN_HEIGHT = 480;

	private:
		SDL_Window* window;
		SDL_Surface* screenSurface;
		SDL_Renderer* renderer;
		bool initialized;
};

#endif