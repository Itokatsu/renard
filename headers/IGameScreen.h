#ifndef DEF_GAMESCREEN
#define DEF_GAMESCREEN

#include "GameEngine.h"
#include "SDL.h"

/*Pure abstract class 
  i.e. TitleScreen LoadingScreen MenuScreen... */

class IGameScreen
{
	public:
		//Creation of all the IGameScreen's assets
		virtual void Init(GameEngine* game) = 0;
		//Deleting assets
		virtual void Cleanup() = 0;

		//Halts updates of the screen
		virtual void Pause();
		//Resumes the screen updates
		virtual void Unpause();

		/*  Handles things like user inputs */
		virtual void HandleEvents(GameEngine* game) = 0;
		/*  Goes to next frame */
		virtual void Update(GameEngine* game, float dT) = 0;
		/* Draw the screen */
		virtual	void Draw(GameEngine* game) = 0;

		bool IsPaused();
		bool RunBG();
		bool DisplayBG();

	protected:
		bool paused = false;
		//allowing background screen to update
		bool allowRunningBG = false;
		bool displayBG = false;
};

#endif