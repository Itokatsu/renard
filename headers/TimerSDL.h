#ifndef DEF_TIMERSDL
#define DEF_TIMERSDL

#include "SDL.h"

class TimerSDL
{
  public:
	void Start()
	{
		startTime_ = SDL_GetTicks();
		started_ = true;
	}

	Uint32 GetTime()
	{
		return SDL_GetTicks() - startTime_;
	}

	void Reset()
	{
		startTime_ = SDL_GetTicks();
	}

	void Stop()
	{
		startTime_ = 0;
		started_ = false;
	}

	bool IsRunning()
	{
		return started_;
	}

  private:
	Uint32 startTime_;
	bool started_;
};

#endif