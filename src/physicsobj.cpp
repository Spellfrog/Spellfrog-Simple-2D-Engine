#include "PhysicsObj.hpp"
#include "Entity.hpp"

std::vector<PhysicsObj*> PhysicsObj::objList;

void PhysicsObj::update()
{
	const float gravAcc = .075;
	if(!grounded)
		acc.y = gravAcc;
	vel.x += acc.x;
	vel.y += acc.y;
	setPos(Vector2f(getPos().x + vel.x, (getPos().y + vel.y)));
}