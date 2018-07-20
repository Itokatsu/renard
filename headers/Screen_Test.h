#ifndef DEF_SCREEN_TEST
#define DEF_SCREEN_TEST

#include "IGameScreen.h"
#include "Sprite.h"
#include "Bullet.h"

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
	Sprite *bullet_;
	Vec2d center_;
	std::vector<Bullet*> projs_;
};

#endif