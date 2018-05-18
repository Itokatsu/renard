#ifndef DEF_Screen_Sprite
#define DEF_SCREEN_TEST

#include "IGameScreen.h"

class Screen_Sprite : public IGameScreen
{
    
	public:
        enum direction {
            BAS,
            GAUCHE,
            DROITE,
            HAUT
        };
		void Init(GameEngine* game);
		void Cleanup();

		void Pause();
		void Unpause();

		void HandleEvents(GameEngine* game);
		void Update(GameEngine* game, float dT);
		void Draw(GameEngine* game);

		static Screen_Sprite* Instance();

	protected:
		Screen_Sprite();

	private:
		static Screen_Sprite myScreen;
		SDL_Texture* texture_png;

        int sprite_height;
        int sprite_width;
		double sprite_xspeed;
		double sprite_yspeed;
        int sprite_x;
        int sprite_y;
        direction sprite_direction;
		float anim_time;
        int sprite_currentImg;
        int sprite_maxImg;
};

#endif