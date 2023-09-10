#pragma once

#include <vector>

#include "Entity.hpp"
#include "PhysicsManager.hpp"

class PhysicsObj : public Entity
{
public:
	explicit PhysicsObj(Vector2f p_pos, SDL_Texture* p_tex, float p_gravForce)
	 : Entity(p_pos, p_tex), pos(p_pos), tex(p_tex), gravForce(p_gravForce)
	{
		grounded = false;

		if(!grounded)
			vel.y = gravForce * physicsManager.getGlobalGravForce();

		std::cout << "PhysicsObj created" << std::endl;
		this->getPos().print();

		currentFrame.x = 0;
		currentFrame.y = 0;
		currentFrame.w = 48;
		currentFrame.h = 48;

		objList.push_back(this);
		objList[0]->getPos().print();
	}

	float getGravForce()
	{
		return gravForce;
	}

	void update();

	static std::vector<PhysicsObj*> getAllObjects()
	{
		return objList;
	}
private:
	Vector2f pos;
	Vector2f vel;
	Vector2f acc;

	bool grounded;

	SDL_Rect currentFrame;
	SDL_Texture* tex;

	float gravForce;

	static std::vector<PhysicsObj*> objList;
};