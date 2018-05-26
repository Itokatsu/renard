#ifndef DEF_SCREEN_SPRITE
#define DEF_SCREEN_SPRITE

#include "IGameScreen.h"
#include "IEntity.h"
#include "Player.h"
#include "EnemyWave.h"

class Screen_Sprite : public IGameScreen
{

  public:
	void Init(GameEngine *game);
	void Cleanup();

	void Pause();
	void Unpause();

	void HandleEvents(GameEngine *);
	void Update(GameEngine *, double);
	void Draw(GameEngine *);

	static Screen_Sprite *Instance();

  protected:
	Screen_Sprite();

  private:
	static Screen_Sprite myScreen_;
	std::vector<IEntity*> entities_;
	Player *thePlayer_;
	EnemyWave* wave_;
};

#endif