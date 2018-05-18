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

	Mix_Music *loadMusic(std::string path);
	Mix_Chunk *loadChunk(std::string path);

  private:
	std::vector<Mix_Chunk *> ressources_chunks;
	std::vector<Mix_Music *> ressources_musics;
};

#endif