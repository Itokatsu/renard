#include "GameEngine.h"
#include "IGameScreen.h"
#include "Screen_Sprite.h"

#include <iostream>

bool GameEngine::Init(int width, int height)
{
	bool success = true;
	
	// init graphic engine
	gfx = new GraphicEngine();
	if (!gfx->Init(width, height)) 
	{ 
		success = false;
	}
	else {
		windowHeight = height;
		windowWidth = width;
		//init draw engine
		drawer = new DrawEngine();
		if (!drawer->Init(gfx)) {
			success = false;
		}
	}

	// init sound engine
	sound = new SoundEngine();
	if(!sound->Init()) 
	{
		success = false;
	}

	// if init succeeded
	if (success) {
		// start intro
		screens.push_back(Screen_Sprite::Instance());
		// init intro
		screens.back()->Init(this);

		//start timers
		framesThisSec = 0;
		runTime.start();
		updateTime.start();
		FPSTimer.start();
		running = true;
	}

	return success;
}

void GameEngine::Cleanup()
{
	// clear the stack
	while (!screens.empty()) {
		screens.back()->Cleanup();
		screens.pop_back();
	}
	screens.clear();
	// clean draw engine
	drawer->Cleanup();
	delete drawer;
	drawer = NULL;

	// clean graphic engine
	gfx->Cleanup();
	delete gfx;
	gfx = NULL;

}

void GameEngine::ChangeScreen(IGameScreen* screen)
{
	//quit current Screen
	if (!screens.empty()) {
		screens.back()->Cleanup();
		screens.pop_back();
	}

	//add new screen
	screens.push_back(screen);
	screens.back()->Init(this);
}

void GameEngine::PushScreen(IGameScreen* screen)
{
	//pause current screen
	if (!screen->RunBG()) {
		screens.back()->Pause();
	}

	//start new top screen
	screens.push_back(screen);
	screens.back()->Init(this);
}

void GameEngine::PopScreen()
{
	//remove current screen
	if (!screens.empty()) {
		screens.back()->Cleanup();
		screens.pop_back();
	}

	//resume previous screen
	if (!screens.empty() && screens.back()->IsPaused()) {
		screens.back()->Unpause();
	}

	//no screen > exit game
	if (screens.empty()) {
		this->Quit();
	}
}

//let current screen handle events, update and draw
void GameEngine::HandleEvents()
{
	screens.back()->HandleEvents(this);
}

void GameEngine::Update()
{
	// get time since last update
	Uint32 diff = updateTime.getTime(); //ms
	updateTime.reset();

	float dTime = diff*60 / 1000.f; // convert to 1/60ths of second
	dTime = diff;
	// Outputs FPS every second
	if (FPSTimer.getTime() >= 1000) { //1sec passed
		std::cout << "FPS : " << framesThisSec << std::endl;
		// Reset counter
		FPSTimer.reset();
		framesThisSec = 0;
	}

	// Top of the stack
	unsigned int idx = screens.size()-1;
	// Find highest screen in the stack not accepting screens running in the background
	while ( screens.at(idx)->RunBG() ) {
		if (idx == 0) {
			break;
		}
			idx--;
	}
	// Update all screens till back at the top
	while ( idx <= screens.size()-1) {
		screens.at(idx)->Update(this, dTime);
		idx++;
	}

	// Add one frame to FPS counter
	framesThisSec++;
}

void GameEngine::Draw()
{
	//Clear the screen
	SDL_SetRenderDrawColor( gfx->GetRenderer(), 0x2A, 0x2A, 0x34, 0xFF );
	SDL_RenderClear( gfx->GetRenderer() );

	
	unsigned int idx = screens.size()-1; // Top of the stack
	// Find highest screen in the stack not accepting screens displaying in the background
	while ( screens.at(idx)->DisplayBG() ) {
		if (idx == 0) {
			break;
		}
			idx--;
	}
	// Display all screens till back at the top
	while ( idx <= screens.size()-1) {
		screens.at(idx)->Draw(this);
		idx++;
	}

	// Update the display
	SDL_RenderPresent( gfx->GetRenderer() );
}

void GameEngine::Quit()
{
	running = false; // Will quit the main loop
}

bool GameEngine::IsRunning()
{
	return running;
}

int GameEngine::GetWindowHeight() {
	return windowHeight;
}

int GameEngine::GetWindowWidth() {
	return windowWidth;
}

GraphicEngine* GameEngine::GetGraphicEngine()
{
	return gfx;
}

DrawEngine* GameEngine::GetDrawEngine()
{
	return drawer;
}

SoundEngine* GameEngine::GetSoundEngine()
{
	return sound;
}