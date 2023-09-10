#pragma once

class PhysicsManager
{
public:
	PhysicsManager() {};

	float getGlobalGravForce()
	{
		return globalGravForce;
	}

	float setGlobalGravForce(float n)
	{
		globalGravForce = n;
		return globalGravForce;
	}

	void updateAll();
private:
	float globalGravForce;
};

extern PhysicsManager physicsManager;