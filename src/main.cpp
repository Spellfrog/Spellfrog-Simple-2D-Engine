#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "GameManager.hpp"

extern GameManager game;

int main(int argv, char* args[])
{
	game.init();

	while(game.gameRunning)
	{
		game.update();
	}

	game.getWindow().cleanUp();
	SDL_Quit();

	return 0;
}