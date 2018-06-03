#include "GameEngine.h"
#include "IGameScreen.h"
#include "Screen_Menu.h"

#include <iostream>

bool GameEngine::Init(int width, int height)
{
	bool success = true;

	// init graphic engine
	gfx_ = new GraphicEngine();
	if (!gfx_->Init(width, height))
	{
		success = false;
	}
	else
	{
		windowHeight_ = height;
		windowWidth_ = width;
		//init draw engine
		drawer_ = new DrawEngine();
		if (!drawer_->Init(gfx_))
		{
			success = false;
		}
	}

	// init sound engine
	sound_ = new SoundEngine();
	if (!sound_->Init())
	{
		success = false;
	}

	// if init succeeded
	if (success)
	{
		// start intro
		screens_.push_back(Screen_Menu::Instance());
		// init intro
		screens_.back()->Init(this);

		//start timers
		framesThisSec_ = 0;
		runTime_.Start();
		updateTime_.Start();
		fpsTimer_.Start();
		running_ = true;
	}

	return success;
}

void GameEngine::Cleanup()
{
	// clear the stack
	while (!screens_.empty())
	{
		screens_.back()->Cleanup();
		screens_.pop_back();
	}
	screens_.clear();
	// clean draw engine
	drawer_->Cleanup();
	delete drawer_;
	drawer_ = NULL;

	// clean graphic engine
	gfx_->Cleanup();
	delete gfx_;
	gfx_ = NULL;
}

// Change the screen on top of the stack
void GameEngine::ChangeScreen(IGameScreen *screen)
{
	if (!screens_.empty())
	{
		// exit and remove current Screen
		screens_.back()->Cleanup();
		screens_.pop_back();
	}

	// start new screen
	screens_.push_back(screen);
	screens_.back()->Init(this);
}

// Add a screen on top of the stack
void GameEngine::PushScreen(IGameScreen *screen)
{
	// pause current screen
	if (!screen->RunBG())
	{
		screens_.back()->Pause();
	}

	// start new screen
	screens_.push_back(screen);
	screens_.back()->Init(this);
}

// Remove the screen on top of the stack
void GameEngine::PopScreen()
{
	// remove current screen
	if (!screens_.empty())
	{
		screens_.back()->Cleanup();
		screens_.pop_back();
	}

	// resume previous screen
	if (!screens_.empty() && screens_.back()->IsPaused())
	{
		screens_.back()->Unpause();
	}

	// exit game if there is no screen left
	if (screens_.empty())
	{
		this->Quit();
	}
}

//let current screen handle events, update and draw
void GameEngine::HandleEvents()
{
	screens_.back()->HandleEvents(this);
}

void GameEngine::Update()
{
	// get time since last update
	Uint32 diff = updateTime_.GetTime(); //ms
	updateTime_.Reset();

	float dTime = diff * 60 / 1000.f; // convert to 1/60ths of second
	dTime = diff;
	// Outputs FPS every second
	if (fpsTimer_.GetTime() >= 1000)
	{ // 1sec passed
		std::cout << "FPS : " << framesThisSec_ << std::endl;
		// Reset counter
		fpsTimer_.Reset();
		framesThisSec_ = 0;
	}

	// Top of the stack
	unsigned int idx = screens_.size() - 1;
	// Find highest screen in the stack not accepting screens running in the background
	while (screens_.at(idx)->RunBG())
	{
		if (idx == 0)
		{
			break;
		}
		idx--;
	}
	// Update all screens till back at the top
	while (idx <= screens_.size() - 1)
	{
		screens_.at(idx)->Update(this, dTime);
		idx++;
	}

	// Add one frame to FPS counter
	framesThisSec_++;
}

void GameEngine::Draw()
{
	//Clear the screen
	SDL_SetRenderDrawColor(gfx_->GetRenderer(), 0x2A, 0x2A, 0x34, 0xFF);
	SDL_RenderClear(gfx_->GetRenderer());

	/* @TODO: refacto */
	unsigned int idx = screens_.size() - 1; // Top of the stack
	// Find highest screen in the stack not accepting screens displaying in the background
	while (screens_.at(idx)->DisplayBG())
	{
		if (idx == 0)
		{
			break;
		}
		idx--;
	}
	// Display all screens till back at the top
	while (idx <= screens_.size() - 1)
	{
		screens_.at(idx)->Draw(this);
		idx++;
	}

	// Update the display
	SDL_RenderPresent(gfx_->GetRenderer());
}

void GameEngine::Quit()
{
	// Will quit the main loop
	running_ = false;
}

bool GameEngine::IsRunning()
{
	return running_;
}

// Application window height
int GameEngine::GetWindowHeight()
{
	return windowHeight_;
}

// Application window width
int GameEngine::GetWindowWidth()
{
	return windowWidth_;
}

// Used for rendering stuff
GraphicEngine *GameEngine::GetGraphicEngine()
{
	return gfx_;
}

// Used to load and manage images
DrawEngine *GameEngine::GetDrawEngine()
{
	return drawer_;
}

// Does what you expect
SoundEngine *GameEngine::GetSoundEngine()
{
	return sound_;
}