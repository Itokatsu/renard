#ifndef DEF_GRAPHENGINE
#define DEF_GRAPHENGINE

#include "SDL.h"

class GraphicEngine
{
  public:
	GraphicEngine();
	bool Init(int height, int width);
	void Cleanup();
	SDL_Renderer *GetRenderer();

  private:
	SDL_Window *window_;
	SDL_Surface *screenSurface_;
	SDL_Renderer *renderer_;
	bool initialized_;
};

#endif