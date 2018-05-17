#include "Screen_Sprite.h"
#include <iostream>
#include "SDL.h"


Screen_Sprite Screen_Sprite::myScreen;

Screen_Sprite::Screen_Sprite()
{

}

void Screen_Sprite::Init(GameEngine* game)
{
	// texture_title = game->GetDrawEngine()->CreateTexture("../media/img/logoa2balles.png");
	texture_png = game->GetDrawEngine()->LoadImage("media/img/sprite.png");
	sprite_height = 128 / 4;
	sprite_width = 96 / 3;
	sprite_x = sprite_width * 2;
	sprite_y = sprite_height;
	sprite_currentImg = 0;
	sprite_maxImg = 3;
	std::cout << "[Sprite Screen Start]" << std::endl;
}

void Screen_Sprite::Cleanup()
{
	std::cout << "[Sprite Screen Quit]" << std::endl;
}

void Screen_Sprite::Pause()
{

}

void Screen_Sprite::Unpause()
{

}

void Screen_Sprite::HandleEvents(GameEngine* game)
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

				// Directions
				if (e.key.keysym.sym == SDLK_UP) {
					sprite_direction = direction::HAUT;
					sprite_y = std::max(sprite_y - 1, 0);
					sprite_currentImg = (sprite_currentImg + 1) % sprite_maxImg;
				}
				if (e.key.keysym.sym == SDLK_DOWN) {
					sprite_direction = direction::BAS;
					sprite_y = std::min(sprite_y + 1, game->GetWindowHeight() - sprite_height);
					sprite_currentImg = (sprite_currentImg + 1) % sprite_maxImg;
				}
				if (e.key.keysym.sym == SDLK_RIGHT) {
					sprite_direction = direction::DROITE;
					sprite_x = std::min(sprite_x + 1, game->GetWindowWidth() - sprite_width);
					sprite_currentImg = (sprite_currentImg + 1) % sprite_maxImg;
				}
				if (e.key.keysym.sym == SDLK_LEFT) {
					sprite_direction = direction::GAUCHE;
					sprite_x = std::max(sprite_x - 1, 0);
					sprite_currentImg = (sprite_currentImg + 1) % sprite_maxImg;
				}
			}
		}
	}
}

void Screen_Sprite::Update(GameEngine*, float)
{
}

void Screen_Sprite::Draw(GameEngine* game)
{
	SDL_Renderer* rend = game->GetGraphicEngine()->GetRenderer();
	SDL_Rect spriteFrame;
	SDL_Rect coord;
	spriteFrame.x = sprite_currentImg * sprite_width;
	spriteFrame.y = sprite_direction * sprite_height;
	spriteFrame.w = sprite_width;
	spriteFrame.h = sprite_height; 
	coord = { sprite_x, sprite_y, sprite_width, sprite_height };


	SDL_RenderCopy( rend, texture_png, &spriteFrame, &coord );
}

Screen_Sprite* Screen_Sprite::Instance()
{
	return &myScreen;
}