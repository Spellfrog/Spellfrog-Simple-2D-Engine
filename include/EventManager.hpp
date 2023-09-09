#pragma once

#include <SDL2/SDL.h>

#include "GameManager.hpp"
#include "Ball.hpp"
#include "Math.hpp"

class EventManager
{
public:
	EventManager() {};
	void watchEvent();
	void readEvent();

private:
	SDL_Event e;
};

extern EventManager eventManager;