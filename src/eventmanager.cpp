#include "EventManager.hpp"

#include <SDL2/SDL.h>

#include "GameManager.hpp"
#include "Ball.hpp"
#include "Math.hpp"

extern void createBall(Vector2f p_pos);

SDL_Event e;

void EventManager::watchEvent()
{
	while(SDL_PollEvent(&e))
	{
		readEvent();
	}
}

void EventManager::readEvent()
{
	switch (e.type)
    {
        case SDL_QUIT:
            game.gameRunning = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
        	// while(e.type == SDL_MOUSEBUTTONDOWN)
        	// 	mouseHolding();
        	createBall(Vector2f(e.button.x, e.button.y));
        	break;
    }
}

// void EventManager::mouseHolding()
// {
// 	std::cout << "holding" << std::endl;
// }