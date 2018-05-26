#ifndef DEF_SCREEN_TEST
#define DEF_SCREEN_TEST

#include "IGameScreen.h"

class Screen_Test : public IGameScreen
{
  public:
	void Init(GameEngine *game);
	void Cleanup();

	void Pause();
	void Unpause();

	void HandleEvents(GameEngine *game);
	void Update(GameEngine *game, double dT);
	void Draw(GameEngine *game);

	static Screen_Test *Instance();

  protected:
	Screen_Test();

  private:
	static Screen_Test myTest_;
	SDL_Texture *textureText_;
	SDL_Texture *texturePng_;
	Mix_Music *bgMusic_;
};

#endif