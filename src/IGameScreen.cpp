#include "IGameScreen.h"
#include <iostream>

void IGameScreen::Pause()
{
	if (!paused) {
		paused = true;
	}
}

void IGameScreen::Unpause()
{
	if (paused) {
		paused = false;
	}
}

bool IGameScreen::IsPaused() 
{
	return paused;
}

bool IGameScreen::RunBG()
{
	return allowRunningBG;
}

bool IGameScreen::DisplayBG()
{
	return displayBG;
}