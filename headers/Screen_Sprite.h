#ifndef DEF_SCREEN_SPRITE
#define DEF_SCREEN_SPRITE

#include "IGameScreen.h"
#include "Player.h"
class Screen_Sprite : public IGameScreen
{

  public:
	void Init(GameEngine *game);
	void Cleanup();

	void Pause();
	void Unpause();

	void HandleEvents(GameEngine *);
	void Update(GameEngine *, float);
	void Draw(GameEngine *);

	static Screen_Sprite *Instance();

  protected:
	Screen_Sprite();

  private:
	static Screen_Sprite myScreen;
	SDL_Texture *texture_png;
	Player* thePlayer;
};

#endif