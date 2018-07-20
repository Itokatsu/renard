#include "DrawEngine.h"
#include <iostream>

DrawEngine::DrawEngine() {}

// Initialize SDL_Image and SDL_TTF
bool DrawEngine::Init(GraphicEngine *gfx)
{
	bool success = true;
	renderer_ = gfx->GetRenderer();

	// init SDL_image
	int imgFlags = IMG_INIT_PNG; //Loading PNGs
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		std::cerr << "SDL_image init FAILED : " << IMG_GetError() << std::endl;
		success = false;
	}

	// init SDL_ttf
	if (TTF_Init() == -1)
	{
		std::cerr << "SDL_ttf init FAILED : " << TTF_GetError() << std::endl;
		success = false;
	}
	font_ = TTF_OpenFont("media/fonts/Roboto-Medium.ttf", 28);
	if (font_ == NULL)
	{
		std::cerr << "Failed to open font : " << TTF_GetError() << std::endl;
		success = false;
	}

	return success;
}

void DrawEngine::Cleanup()
{
	// clean ressources map
	for (auto &pair : ressources_)
	{
		SDL_Texture *texture = pair.second;
		if (texture != NULL)
		{
			SDL_DestroyTexture(texture);
		}
		texture = NULL;
	}
	ressources_.clear();

	TTF_CloseFont(font_);
	font_ = NULL;

	TTF_Quit();
	IMG_Quit();
}

// Imgfile -> Texture
SDL_Texture *DrawEngine::LoadImage(std::string imgPath)
{
	// Look for texture in ressources map.
	int const pos = imgPath.find_last_of('/');
	const std::string leaf = imgPath.substr(pos + 1);
	if (GetRessource(leaf) != NULL)
	{
		// Returns it directly when found
		return ressources_.at(leaf);
	}

	// Load with SDL_Image
	SDL_Texture *newTexture = NULL;
	SDL_Surface *tempSurface = IMG_Load(imgPath.c_str());
	if (tempSurface == NULL)
	{
		std::cerr << "Failed to load " << imgPath << " : " << IMG_GetError() << std::endl;
	}
	else
	{
		SDL_SetColorKey( tempSurface, SDL_TRUE, SDL_MapRGB( tempSurface->format, 0x00, 0x00, 0x00 ) );
		newTexture = SDL_CreateTextureFromSurface(renderer_, tempSurface);
		if (newTexture == NULL)
		{
			std::cerr << "Failed to create texture from " << imgPath << " : " << SDL_GetError() << std::endl;
		}
		SDL_FreeSurface(tempSurface);
	}

	// Push into ressources map.
	ressources_[leaf] = newTexture;
	return newTexture;
}

// Create a texture with your text.
SDL_Texture *DrawEngine::LoadText(std::string text, SDL_Color color)
{
	SDL_Texture *newTexture = NULL;
	SDL_Surface *tempSurface = TTF_RenderUTF8_Solid(font_, text.c_str(), color);
	if (tempSurface == NULL)
	{
		std::cerr << "Failed to render text surface : " << TTF_GetError() << std::endl;
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(renderer_, tempSurface);
		if (newTexture == NULL)
		{
			std::cerr << "Failed to create texture from rendered text : " << SDL_GetError() << std::endl;
		}
		//Get rid of old surface
		SDL_FreeSurface(tempSurface);
	}

	return newTexture;
}

Sprite *DrawEngine::LoadSprite(std::string imgPath, int width, int height, unsigned int numFrames)
{
	// Look for texture in sprites map.
	int const pos = imgPath.find_last_of('/');
	const std::string leaf = imgPath.substr(pos + 1);
	if (GetSprite(leaf) != NULL)
	{
		// Returns it directly when found
		return sprites_.at(leaf);
	}

	SDL_Texture *tex = LoadImage(imgPath);
	Sprite *newSprite = new Sprite(tex, width, height, numFrames);

	// Push into map.
	sprites_[leaf] = newSprite;
	return newSprite;
}

// Look into ressources map
SDL_Texture *DrawEngine::GetRessource(std::string key)
{
	int c = ressources_.count(key);
	if (c == 0)
		return NULL;
	return ressources_.at(key);
}

Sprite *DrawEngine::GetSprite(std::string key)
{
	int c = sprites_.count(key);
	if (c == 0)
		return NULL;
	return sprites_.at(key);
}