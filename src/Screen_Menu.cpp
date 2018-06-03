#include "Screen_Menu.h"
#include <iostream>
#include "SDL.h"

#include "Screen_Sprite.h"
#include "Screen_Test.h"

Screen_Menu Screen_Menu::myMenu_;

Screen_Menu::Screen_Menu()
{
}

void Screen_Menu::Init(GameEngine *game)
{
	SDL_Color textColor = {0xBB, 0xBB, 0xBB, 0xFF};
	selected_ = 0;
	menuItems_.push_back(game->GetDrawEngine()->LoadText("Start Game", textColor));
	menuItems_.push_back(game->GetDrawEngine()->LoadText("Toggle Music", textColor));
	menuItems_.push_back(game->GetDrawEngine()->LoadText("Exit", textColor));

	// Start Music
	bgMusic_ = game->GetSoundEngine()->LoadMusic("media/sound/Wolf.mp3");
	Mix_PlayMusic(bgMusic_, -1);
	std::cout << "[TEST Menu Start]" << std::endl;
}

void Screen_Menu::Cleanup()
{
	menuItems_.clear();
	std::cout << "[TEST Menu Quit]" << std::endl;
}

void Screen_Menu::Pause()
{
}

void Screen_Menu::Unpause()
{
}

void Screen_Menu::HandleEvents(GameEngine *game)
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		//Close window
		if (e.type == SDL_QUIT)
		{
			game->Quit();
		}
		else
		{
			// Key press
			if (e.type == SDL_KEYDOWN)
			{
				// ESCAPE is pressed
				switch (e.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					game->PopScreen();
					break;

				case SDLK_DOWN:
				{
					selected_ = (selected_ + 1) % menuItems_.size();
					break;
				}

				case SDLK_UP:
				{
					selected_--;
					if (selected_ < 0)
					{
						selected_ = menuItems_.size() - 1;
					}
					break;
				}

				case SDLK_RETURN:
					switch (selected_)
					{
					case 0:
						game->PushScreen(Screen_Sprite::Instance());
						break;

					case 1:
						if (Mix_PlayingMusic() == 0)
						{
							Mix_PlayMusic(bgMusic_, -1);
						}
						else
						{
							if (Mix_PausedMusic() == 1)
							{
								Mix_ResumeMusic();
							}
							else
							{
								Mix_PauseMusic();
							}
						}
						break;

					case 2:
						game->PopScreen();
						break;
					}

				/*case SDLK_t:
					game->PushScreen(Screen_Test::Instance());
					break;*/
				}
			}
		}
	}
}
void Screen_Menu::Update(GameEngine *, double)
{
}

void Screen_Menu::Draw(GameEngine *game)
{
	SDL_Renderer *rend = game->GetGraphicEngine()->GetRenderer();

	unsigned int idx = 0;
	while (idx < menuItems_.size())
	{
		SDL_Rect area = {100, 200 + 80 * (int)idx, 250, 50};
		SDL_RenderCopy(rend, menuItems_.at(idx), NULL, &area);
		if (idx == selected_)
		{
			SDL_SetRenderDrawColor(rend, 0xFF, 0x00, 0x00, 0x80);
			SDL_RenderFillRect(rend, &area);
		}
		idx++;
	}
}

Screen_Menu *Screen_Menu::Instance()
{
	return &myMenu_;
}