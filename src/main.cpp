#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

int main(int argv, char* args[])
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		std::cout << "Womp womp video init failed: " << SDL_GetError() << std::endl;
	else
		std::cout << "Yayyyy vido succeed :3" << std::endl;

	RenderWindow window("Basic 2D Physics Engine", 1280, 720);

	bool gameRunning = true;

	SDL_Texture* ballTexture = window.loadTexture("res/gfx/8ball.png");

	Entity entity(Vector2f(50, 50), ballTexture);

	SDL_Event event;

	while(gameRunning)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				gameRunning = false;
		}

		window.render(entity);

		window.display();

		window.clear();
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}