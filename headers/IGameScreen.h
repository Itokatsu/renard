#ifndef DEF_GAMESCREEN
#define DEF_GAMESCREEN

#include "GameEngine.h"
/*Pure abstract class 
  i.e. TitleScreen LoadingScreen MenuScreen... */

class IGameScreen
{
	public:
		//Creation of all the IGameScreen's assets
		virtual void Init(GameEngine*) = 0;
		//Deleting assets
		virtual void Cleanup() = 0;

		//Halts updates of the screen
		virtual void Pause();
		//Resumes the screen updates
		virtual void Unpause();

		/*  Handles things like user inputs */
		virtual void HandleEvents(GameEngine*) = 0;
		/*  Goes to next frame */
		virtual void Update(GameEngine*, float) = 0;
		/* Draw the screen */
		virtual	void Draw(GameEngine*) = 0;

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