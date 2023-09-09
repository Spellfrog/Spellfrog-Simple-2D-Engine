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
        	createBall(Vector2f(e.button.x / 4 - (48 / 2), e.button.y / 4 - (48 / 2)));
        	break;
    }
}