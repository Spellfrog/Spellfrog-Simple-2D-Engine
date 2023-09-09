#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "GameManager.hpp"

SDL_Texture* eightBallTex(RenderWindow window)
{
	return window.loadTexture("res/gfx/8ball.png");
}