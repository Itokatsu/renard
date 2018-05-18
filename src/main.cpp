//Using SDL and standard IO
#include <iostream>
#include <vector>
#include <string>

#include "GameEngine.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
	//parse arguments
	std::vector<std::string> arguments;
	for ( int i = 0; i < argc; i++ ) {
		arguments.push_back(args[i]);
	}

	//arguments processing
	//TO DO
	arguments.clear();

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