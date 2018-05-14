#ifndef DEF_DRAWENGINE
#define DEF_DRAWENGINE

#include <string>
#include <map>

#include "GameEngine.h"
#include "GraphicEngine.h"

#include "SDL_image.h"
#include "SDL_ttf.h"
class GameEngine;

class DrawEngine {

	public:
		DrawEngine();
		bool Init(GraphicEngine* gfx);
		void Cleanup();
		void Load(std::string className, std::string file);
		SDL_Texture* LoadImage(std::string imgPath);
		SDL_Texture* LoadText(std::string text, SDL_Color color);

	private:
		std::map<std::string, SDL_Texture*> ressources;
		SDL_Renderer* renderer;
		TTF_Font* font;
};

#endif