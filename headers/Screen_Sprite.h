#ifndef DEF_SCREEN_SPRITE
#define DEF_SCREEN_SPRITE

#include "IGameScreen.h"
#include "Sprite.h"
class Screen_Sprite : public IGameScreen
{

  public:
	void Init(GameEngine *game);
	void Cleanup();

	void Pause();
	void Unpause();

	void HandleEvents(GameEngine *game);
	void Update(GameEngine *game, float dT);
	void Draw(GameEngine *game);

	static Screen_Sprite *Instance();

  protected:
	Screen_Sprite();

  private:
	static Screen_Sprite myScreen;
	SDL_Texture *texture_png;
	Sprite *mySprite;
	int sprite_x;
	int sprite_y;

	float sprite_xspeed;
	float sprite_yspeed;
};

#endif