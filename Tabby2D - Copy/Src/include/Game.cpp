#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2.h"
#include "KeyListener.h"

Map* map;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;



Manager manager;
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


	player.addComponent<Transform>(200, 200);
	player.addComponent<Sprite>("assets/player.png");
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

	if (KeyListener::getKey(SDLK_w)) {
		std::cout << "W :3" << std::endl;
	}
	else {
		std::cout << "no W :(" << std::endl;
	}


	/*if (keyListener.getComponent<KeyListener>().keyPressed[SDL_SCANCODE_W]) {
		player.getComponent<Transform>().velocity.y = 5;
 	} 

	if (keyListener.getComponent<KeyListener>().keyPressed[SDL_SCANCODE_S]) {
		player.getComponent<Transform>().velocity.y = -5;
	}



	if (keyListener.getComponent<KeyListener>().keyPressed[SDL_SCANCODE_D]) {
		player.getComponent<Transform>().velocity.x = 5;
	}


	if (keyListener.getComponent<KeyListener>().keyPressed[SDL_SCANCODE_A]) {
		player.getComponent<Transform>().velocity.x = -5;
	}

	if (!keyListener.getComponent<KeyListener>().keyPressed[SDL_SCANCODE_W] || !keyListener.getComponent<KeyListener>().keyPressed[SDL_SCANCODE_S]) {
		player.getComponent<Transform>().velocity.y = 0;
	}

	if (!keyListener.getComponent<KeyListener>().keyPressed[SDL_SCANCODE_A] || !keyListener.getComponent<KeyListener>().keyPressed[SDL_SCANCODE_D]) {
		player.getComponent<Transform>().velocity.y = 0;
	}*/


	if (player.getComponent<Transform>().position.y > 100) {
		player.getComponent<Sprite>().setTexture("assets/wierderguy.png");
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