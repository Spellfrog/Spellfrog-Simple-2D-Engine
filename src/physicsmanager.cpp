#include "PhysicsManager.hpp"
#include "PhysicsObj.hpp"
#include "Ball.hpp"

#include <SDL2/SDL.h>

PhysicsManager physicsManager;

void PhysicsManager::updateAll()
{
	for (PhysicsObj* obj : PhysicsObj::getAllObjects())
	{
		obj->update();
	}
}