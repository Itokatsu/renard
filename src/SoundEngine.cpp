#include "SoundEngine.h"
#include <iostream>

SoundEngine::SoundEngine()
{
}

bool SoundEngine::Init()
{
	bool success = true;
	if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0)
	{
		std::cerr << "SDL_AUDIO could not initialize! SDL_Error:" << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		{
			std::cerr << "SDL_MIXER could not initialize! SDL_Mixer Error:" << Mix_GetError() << std::endl;
			success = false;
		}
	}
	return success;
}

Mix_Music *SoundEngine::loadMusic(std::string path)
{
	Mix_Music *m = NULL;
	m = Mix_LoadMUS(path.c_str());
	if (m == NULL)
	{
		std::cerr << "Failed to load music : " << path << ". Error : " << Mix_GetError() << std::endl;
	}
	return m;
}

Mix_Chunk *SoundEngine::loadChunk(std::string path)
{
	Mix_Chunk *c = NULL;
	c = Mix_LoadWAV(path.c_str());
	if (c == NULL)
	{
		std::cerr << "Failed to load music : " << path << ". Error : " << Mix_GetError() << std::endl;
	}
	return c;
}

void SoundEngine::Cleanup()
{
	// delete maps
	for (auto &music : ressources_musics)
	{
		Mix_FreeMusic(music);
		music = NULL;
	}
	for (auto &chunk : ressources_chunks)
	{
		Mix_FreeChunk(chunk);
		chunk = NULL;
	}

	Mix_Quit();
}
