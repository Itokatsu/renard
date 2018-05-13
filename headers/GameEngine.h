#ifndef DEF_GAMEENGINE
#define DEF_GAMEENGINE

#include "SDL.h"

class GameEngine
{
	public:
		// Load and Init Graphic Engines
		int Init(int width, int height);
		// Destroy Engines and clean screens stacks
		void Cleanup();

        bool loadMedia();
/*
		void ChangeScreen(IGameScreen* screen);
		void PushScreen(IGameScreen* screen);
		void PopScreen();
        */

		void HandleEvents();
		void Update();
		void Draw();

		// Exits the program
		void Quit();
		bool IsRunning();

	private:
/*
		// stack of Screens
		std::vector<IGameScreen*> screens;
		// Screens to display
		std::vector<IGameScreen*> screenDisplay;
		// Screens to update
		std::vector<IGameScreen*> screenRun;
*/
        SDL_Window* window;
        SDL_Surface* screenSurface;
        SDL_Surface* helloWorld;
		bool running;

/*
    	// Timers and FPS counter
		// Count ticks since the beginning
		TimerSDL runTime;
		// Count ticks since last update
		TimerSDL updateTime;
		// Count ticks since last FPS display
		TimerSDL FPSTimer;
		// # of frames displayed during last second
		int framesThisSec;
*/
};

#endif
