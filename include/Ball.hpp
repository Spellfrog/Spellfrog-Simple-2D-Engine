#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "GameManager.hpp"
#include "Textures.hpp"

#include "PhysicsObj.hpp"

class Ball : public PhysicsObj
{
public:
	explicit Ball(Vector2f p_pos)
		:PhysicsObj(p_pos, eightBallTex(), 10) 
	{
		currentFrame.x = 0;
		currentFrame.y = 0;
		currentFrame.w = 48;
		currentFrame.h = 48;
	}

private:
	SDL_Rect currentFrame;
};

extern std::vector<Ball> balls;

extern void createBall(Vector2f p_pos);