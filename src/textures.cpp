#include "Textures.hpp"

SDL_Texture* eightBallTex()
{
	return game.getWindow().loadTexture("res/gfx/8ball.png");
}

SDL_Texture* thumbsUpTex()
{
	return game.getWindow().loadTexture("res/gfx/thumbsup.png");
}