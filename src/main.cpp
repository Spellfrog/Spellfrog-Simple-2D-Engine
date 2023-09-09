#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "GameManager.hpp"
#include "Textures.hpp"

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "PhysicsObj.hpp"
#include "Ball.hpp"

extern GameManager game;

int main(int argv, char* args[])
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		std::cout << "Womp womp video init failed: " << SDL_GetError() << std::endl;
	else
		std::cout << "Yayyyy vido succeed :3" << std::endl;

	bool gameRunning = true;

	std::vector<Ball> balls =
	{
		Ball(Vector2f(50, 50)),
		Ball(Vector2f(100, 100)),
	};

	SDL_Event event;

	int index = 0;

	while(gameRunning)
	{
		while(SDL_PollEvent(&event))
		{
			switch (event.type)
	        {
		        case SDL_QUIT:
		            gameRunning = false;
		            break;
		        case SDL_MOUSEBUTTONDOWN:
		        	Ball new_ball(Vector2f(event.button.x / 4 - (48 / 2), event.button.y / 4 - (48 / 2)));
					balls.push_back(new_ball);
		        	std::cout << event.button.x << std::endl;
		        	break;
	        }
		}

		for(Ball& ball : balls)
		{
			index++;
			std::cout << "rendering balls: " << index << std::endl;
			game.getWindow().render(ball);
		}

		game.getWindow().display();

		game.getWindow().clear();
	}

	game.getWindow().cleanUp();
	SDL_Quit();

	return 0;
}