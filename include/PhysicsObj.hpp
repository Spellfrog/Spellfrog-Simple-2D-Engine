#pragma once

#include "Entity.hpp"

class PhysicsObj : public Entity
{
public:
	explicit PhysicsObj(Vector2f p_pos, SDL_Texture* p_tex, float p_gravForce)
	 : Entity(p_pos, p_tex), pos(p_pos), tex(p_tex), gravForce(p_gravForce)
	{
		currentFrame.x = 0;
		currentFrame.y = 0;
		currentFrame.w = 48;
		currentFrame.h = 48;
	}

	float getGravForce()
	{
		return PhysicsObj::gravForce;
	}
private:
	Vector2f pos;

	SDL_Rect currentFrame;
	SDL_Texture* tex;

	float gravForce;
};