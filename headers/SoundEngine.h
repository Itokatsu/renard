#ifndef DEF_SOUNDENGINE
#define DEF_SOUNDENGINE

#include <string>
#include <vector>

#include <SDL.h>
#include "SDL_mixer.h"
class GameEngine;

class SoundEngine
{

  public:
	SoundEngine();
	bool Init();
	void Cleanup();

	Mix_Music *LoadMusic(std::string path);
	Mix_Chunk *LoadChunk(std::string path);

  private:
	std::vector<Mix_Chunk *> ressourcesChunks_;
	std::vector<Mix_Music *> ressourcesMusics_;
};

#endif