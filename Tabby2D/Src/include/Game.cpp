#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2.h"
#include "Input.h"

Map* map;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;



Manager manager;

auto& inputComp(manager.addEntity());
Input input;
auto& player(manager.addEntity());

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;
	
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}

	map = new Map();

	inputComp.addComponent<KeyListenerComp>();

	player.addComponent<Transform>();
	player.addComponent<Sprite>("assets/player.png");
	player.addComponent<RigidBody>();

	player.getComponent<RigidBody>().friction = 1;
}

void Game::handleEvents()
{


	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT :
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update() {

	manager.refresh();
	manager.update();

	if (inputComp.getComponent<KeyListenerComp>().getKey(SDL_SCANCODE_D)) {
		std::cout << "Right :3" << std::endl;
		player.getComponent<RigidBody>().velocity.x = 5;
	}

	if (inputComp.getComponent<KeyListenerComp>().getKey(SDL_SCANCODE_A)) {
		std::cout << "Left :3" << std::endl;
		player.getComponent<RigidBody>().velocity.x = -5;
	}

	if (inputComp.getComponent<KeyListenerComp>().getKey(SDL_SCANCODE_W)) {
		std::cout << "Forward :3" << std::endl;
		player.getComponent<RigidBody>().velocity.y = 5;
	}

	if (inputComp.getComponent<KeyListenerComp>().getKey(SDL_SCANCODE_S)) {
		std::cout << "Backwards :3" << std::endl;
		player.getComponent<RigidBody>().velocity.y = -5;
	}

	
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}