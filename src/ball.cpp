#include "Ball.hpp"
#include "Math.hpp"

std::vector<Ball> balls;

void createBall(Vector2f p_pos)
{
	Ball new_ball(p_pos);
	balls.push_back(new_ball);
}