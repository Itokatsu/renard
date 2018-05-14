#include "Screen_Test.h"
#include <iostream>
#include "SDL.h"


Screen_Test Screen_Test::myTest;

Screen_Test::Screen_Test()
{

}

void Screen_Test::Init(GameEngine* game)
{
	// texture_title = game->GetDrawEngine()->CreateTexture("../media/img/logoa2balles.png");
	SDL_Color textColor = { 0xBB, 0xBB, 0xBB, 0xFF };
	texture_text = game->GetDrawEngine()->LoadText("TEST", textColor);
	texture_png = game->GetDrawEngine()->LoadImage("media/img/kyo.png");
	bg_music = game->GetSoundEngine()->loadMusic("media/sound/Wolf.mp3");
	std::cout << "[TEST Screen Start]" << std::endl;
}

void Screen_Test::Cleanup()
{
	std::cout << "[TEST Screen Quit]" << std::endl;
}

void Screen_Test::Pause()
{

}

void Screen_Test::Unpause()
{

}

void Screen_Test::HandleEvents(GameEngine* game)
{
	SDL_Event e;
	while( SDL_PollEvent( &e ) != 0 ) {
		//Close window
		if( e.type == SDL_QUIT ) {
			game->Quit();
		}
		else {
			// Key press 
			if( e.type == SDL_KEYDOWN ) {
				// ESCAPE is pressed
				if (e.key.keysym.sym == SDLK_ESCAPE) {
					game->Quit();
				}
				if (e.key.keysym.sym == SDLK_SPACE) {
					if( Mix_PlayingMusic() == 0 ) {
						Mix_PlayMusic( bg_music, -1 );
					}
					else {
						if( Mix_PausedMusic() == 1 ) {
							Mix_ResumeMusic();
						}
						else {
							Mix_PauseMusic();
						}
					}
				}
			}
		}
	}
}

void Screen_Test::Update(GameEngine*, float)
{
}

void Screen_Test::Draw(GameEngine* game)
{
	SDL_Renderer* rend = game->GetGraphicEngine()->GetRenderer();
	SDL_SetRenderDrawColor( rend, 0x25, 0x25, 0x30, 0xFF );
	SDL_RenderClear( rend );
	
	SDL_Rect fillRect = { 80, 30, 640-160, 30 };
	SDL_SetRenderDrawColor( rend, 0xFF, 0x55, 0x55, 0xFF );
	SDL_RenderFillRect( rend, &fillRect );

	 for(int x = 0; x <= 640; x+= 80) 
	 {
		for (int y = 0; y <= 480; y+=30 ) 
		{
			SDL_Rect area = {x, y, 70, 28};
			SDL_RenderCopy( rend, texture_text, NULL, &area);
		}
	}
	SDL_Rect png_area = {135,105,370,300};
	SDL_RenderCopy( rend, texture_png, NULL, &png_area);
}

Screen_Test* Screen_Test::Instance()
{
	return &myTest;
}