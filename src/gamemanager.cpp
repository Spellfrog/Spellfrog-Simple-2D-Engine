#include "GameManager.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Ball.hpp"
#include "EventManager.hpp"

GameManager game;
EventManager eventManager;

void GameManager::init()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		std::cout << "Womp womp video init failed: " << SDL_GetError() << std::endl;
	else
		std::cout << "Yayyyy vido succeed :3" << std::endl;
}

void GameManager::update()
{
	eventManager.watchEvent();

	for(Ball& ball : balls)
	{
		std::cout << "rendering balls" << std::endl;
		game.getWindow().render(ball);
	}

	game.getWindow().display();

	game.getWindow().clear();
}