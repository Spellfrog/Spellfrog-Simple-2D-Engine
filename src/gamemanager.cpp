#include "GameManager.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Ball.hpp"
#include "EventManager.hpp"
#include "PhysicsManager.hpp"
#include "PhysicsObj.hpp"

extern PhysicsManager physicsManager;

GameManager game;
EventManager eventManager;

void GameManager::init()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		std::cout << "Womp womp video init failed: " << SDL_GetError() << std::endl;
	else
		std::cout << "Yayyyy vido succeed :3" << std::endl;

	physicsManager.setGlobalGravForce(.175);
}

void GameManager::update()
{
	eventManager.watchEvent();

	physicsManager.updateAll();

	for(Entity* e : Entity::getAllObjects())
	{
		game.getWindow().render(*e);
	}

	game.getWindow().display();

	game.getWindow().clear();

	SDL_Delay(10);
}