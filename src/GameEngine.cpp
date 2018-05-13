#include "GameEngine.h"
#include <iostream>

bool GameEngine::loadMedia() 
{
	 //Loading success flag 
	 bool success = true;

 	//Load splash image 
	 helloWorld = SDL_LoadBMP( "media/img/hello_world.bmp" ); 
	 if( helloWorld == NULL ) 
	 { 
		printf( "Unable to load image %s! SDL Error: %s\n", "media/img/hello_world.bmp", SDL_GetError() );
	    success = false; 
	}
	return success;
}

int GameEngine::Init(int width, int height)
{
    //The window we'll be rendering to
	window = NULL;
	//The surface contained by the window
	screenSurface = NULL;
    
    bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface( window );
		}
	}

    if( !loadMedia() )
    {
        printf( "Failed to load media" );
        success = false;
    }
    running = true;
    return success;
}

void GameEngine::Cleanup() 
{
	SDL_FreeSurface( helloWorld );
	helloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow( window );
	window = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

void GameEngine::HandleEvents()
{
    SDL_Event e;
    while( SDL_PollEvent( &e) != 0 )
    {
        if( e.type == SDL_QUIT ) 
        {
            Quit();
        }
    }
}

void GameEngine::Update()
{
    //Update the surface 
    SDL_UpdateWindowSurface( window );
}

void GameEngine::Draw()
{
    SDL_BlitSurface( helloWorld, NULL, screenSurface, NULL );
}

void GameEngine::GameEngine::Quit()
{
    running = false;
}

bool GameEngine::IsRunning()
{
    return running;
}