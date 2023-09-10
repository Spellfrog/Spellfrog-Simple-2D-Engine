#include "Ball.hpp"

#include <utility>

#include "Math.hpp"

std::vector<Ball*> balls;

void createBall(Vector2f p_pos)
{
	// Create a new Ball object, and push a pointer to it to the balls array, without it going out of scope
	//Ball(Vector2f(p_pos.x / 4 - (48 / 2), p_pos.y / 4 - (48 / 2)))
	balls.push_back(new Ball(Vector2f(p_pos.x / 4 - (48 / 2), p_pos.y / 4 - (48 / 2))));
}