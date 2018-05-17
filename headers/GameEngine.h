#ifndef DEF_GAMEENGINE
#define DEF_GAMEENGINE

#include <vector>
#include "GraphicEngine.h"
#include "DrawEngine.h"
#include "SoundEngine.h"
#include "TimerSDL.h"

class IGameScreen;

class GameEngine
{
	public:
		// Load and Init Graphic Engines
		bool Init(int width, int height);
		// Destroy Engines and clean screens stacks
		void Cleanup();

		void ChangeScreen(IGameScreen* screen);
		void PushScreen(IGameScreen* screen);
		void PopScreen();

		void HandleEvents();
		void Update();
		void Draw();

		// Exits the program
		void Quit();
		bool IsRunning();

		// Getters
		GraphicEngine* GetGraphicEngine();
		DrawEngine* GetDrawEngine();
		SoundEngine* GetSoundEngine();

		int GetWindowWidth();
		int GetWindowHeight();

	private:
		// stack of Screens
		std::vector<IGameScreen*> screens;
		// Screens to display
		std::vector<IGameScreen*> screenDisplay;
		// Screens to update
		std::vector<IGameScreen*> screenRun;

		int windowWidth;
		int windowHeight;

		bool running;
		GraphicEngine* gfx;
		DrawEngine* drawer;
		SoundEngine* sound;

	// Timers and FPS counter
	// Count ticks since the beginning
	TimerSDL runTime;
	// Count ticks since last update
	TimerSDL updateTime;
	// Count ticks since last FPS display
	TimerSDL FPSTimer;
	// # of frames displayed during last second
	int framesThisSec;
};

#endif
