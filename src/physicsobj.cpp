#include "PhysicsObj.hpp"
#include "Entity.hpp"

std::vector<PhysicsObj*> PhysicsObj::objList;

void PhysicsObj::update()
{
	setPos(Vector2f(getPos().x + vel.x, (getPos().y + vel.y)));
}