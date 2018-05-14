#ifndef DEF_TIMERSDL
#define DEF_TIMERSDL

#include "SDL.h"

class TimerSDL 
{
	public:
		void start() 
		{
			startTime = SDL_GetTicks();
			started = true;
		}

		Uint32 getTime() 
		{
			return SDL_GetTicks() - startTime;
		}

		void reset() 
		{
			startTime = SDL_GetTicks();
		}

		void stop() 
		{
			startTime = 0;
			started = false;
		}

		bool isRunning() 
		{
			return started;
		}

	private:
		Uint32 startTime;
		bool started;
};

#endif