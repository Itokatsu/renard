//Using SDL and standard IO
#include <iostream>
#include "GameEngine.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{

	GameEngine game;
	game.Init( SCREEN_WIDTH, SCREEN_HEIGHT );
	while( game.IsRunning() ) {
		game.Draw();
		game.HandleEvents();
		game.Update();
	}

	game.Cleanup();

	return 0;
}