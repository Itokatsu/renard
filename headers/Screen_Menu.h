#ifndef DEF_SCREEN_MENU
#define DEF_SCREEN_MENU

#include "IGameScreen.h"
#include <vector>

class Screen_Menu : public IGameScreen
{
  public:
	void Init(GameEngine *game);
	void Cleanup();

	void Pause();
	void Unpause();

	void HandleEvents(GameEngine *game);
	void Update(GameEngine *, double dt);
	void Draw(GameEngine *game);

	static Screen_Menu *Instance();

  protected:
	Screen_Menu();

  private:
	static Screen_Menu myMenu_;
	std::vector<SDL_Texture*> menuItems_;
	int selected_;
	Mix_Music *bgMusic_;
};

#endif