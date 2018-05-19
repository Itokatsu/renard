#include "IGameScreen.h"
#include <iostream>

void IGameScreen::Pause()
{
	if (!paused_)
	{
		paused_ = true;
	}
}

void IGameScreen::Unpause()
{
	if (paused_)
	{
		paused_ = false;
	}
}

bool IGameScreen::IsPaused()
{
	return paused_;
}

bool IGameScreen::RunBG()
{
	return allowRunningBG_;
}

bool IGameScreen::DisplayBG()
{
	return displayBG_;
}