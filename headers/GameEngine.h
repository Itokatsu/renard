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
	bool Init(int width, int height);
	// Destroy Engines and clean screens stacks
	void Cleanup();

	void ChangeScreen(IGameScreen *screen);
	void PushScreen(IGameScreen *screen);
	void PopScreen();

	void HandleEvents();
	void Update();
	void Draw();

	// Exits the program
	void Quit();
	bool IsRunning();

	// Getters
	GraphicEngine *GetGraphicEngine();
	DrawEngine *GetDrawEngine();
	SoundEngine *GetSoundEngine();

	int GetWindowWidth();
	int GetWindowHeight();

  private:
	// stack of Screens
	std::vector<IGameScreen *> screens_;
	
	int windowWidth_;
	int windowHeight_;

	bool running_;
	GraphicEngine *gfx_;
	DrawEngine *drawer_;
	SoundEngine *sound_;

	// Timers and FPS counter
	// Count ticks since the beginning
	TimerSDL runTime_;
	// Count ticks since last update
	TimerSDL updateTime_;
	// Count ticks since last FPS display
	TimerSDL fpsTimer_;
	// # of frames displayed during last second
	int framesThisSec_;
};

#endif
