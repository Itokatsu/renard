#ifndef DEF_SCREEN_PAUSE
#define DEF_SCREEN_PAUSE

#include "IGameScreen.h"

class Screen_Pause : public IGameScreen
{
	public:
		void Init(GameEngine* game);
		void Cleanup();

		void Pause();
		void Unpause();

		void HandleEvents(GameEngine* game);
		void Update(GameEngine* game, float dt);
		void Draw(GameEngine* game);

		static Screen_Pause* Instance();

	protected:
		Screen_Pause();

	private:
		static Screen_Pause myPause_;

};

#endif