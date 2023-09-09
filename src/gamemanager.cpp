#include "GameManager.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Ball.hpp"

GameManager game;

SDL_Event e;

void GameManager::init()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		std::cout << "Womp womp video init failed: " << SDL_GetError() << std::endl;
	else
		std::cout << "Yayyyy vido succeed :3" << std::endl;
}

void GameManager::update()
{
	while(SDL_PollEvent(&e))
	{
		switch (e.type)
        {
	        case SDL_QUIT:
	            gameRunning = false;
	            break;
	        case SDL_MOUSEBUTTONDOWN:
	        	Ball new_ball(Vector2f(e.button.x / 4 - (48 / 2), e.button.y / 4 - (48 / 2)));
				balls.push_back(new_ball);
	        	std::cout << e.button.x << std::endl;
	        	break;
        }
	}

	for(Ball& ball : balls)
	{
		std::cout << "rendering balls" << std::endl;
		game.getWindow().render(ball);
	}

	game.getWindow().display();

	game.getWindow().clear();
}