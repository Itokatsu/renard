#ifndef DEF_DRAWENGINE
#define DEF_DRAWENGINE

#include "GraphicEngine.h"

#include <string>
#include <map>

#include "SDL_image.h"
#include "SDL_ttf.h"
#include "Sprite.h"
class DrawEngine
{
  public:
	DrawEngine();
	bool Init(GraphicEngine *gfx);
	void Cleanup();
	void Load(std::string className, std::string file);
	SDL_Texture *LoadImage(std::string imgPath);
	Sprite *LoadSprite(std::string imgPath, int width, int height, unsigned int numFrames);
	// external info (XML, CVS) file for non-regular sprites?
	//Sprite *LoadSprite(std::string imgPath, std::string infoPath);

	SDL_Texture *LoadText(std::string text, SDL_Color color);
	SDL_Texture *GetRessource(std::string key);
	Sprite *GetSprite(std::string key);

  private:
	std::map<std::string, SDL_Texture *> ressources_;
	std::map<std::string, Sprite *> sprites_;
	SDL_Renderer *renderer_;
	TTF_Font *font_;
};

#endif