#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2.h"

Map* level;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

SDL_Rect Game::camera = { 0, 0, 800, 640 };

KeyListener Input;

Manager manager;

std::vector<Collider*> Game::colliders;

auto& inputComp(manager.addEntity());
auto& player(manager.addEntity());

const char* mapFile = "assets/textures/terrain_ss.png";

enum groupLabels : std::size_t {

	gMap,
	gPlayers,
	gEnemies,
	gColiders
};

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

	level = new Map();

	level->LoadMap("assets/levels/levelTest2.level", 25, 20);

	inputComp.addComponent<KeyListener>();
	Input = inputComp.getComponent<KeyListener>();

	player.addComponent<Transform>(Vector2(4, 4));
	player.addComponent<Sprite>("assets/textures/player_anims.png", true);
	player.addComponent<RigidBody>();
	player.addComponent<Collider>("player");
	player.addGroup(gPlayers);
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

	if (Input.getKey(SDL_SCANCODE_D)) {

		player.getComponent<RigidBody>().velocity.x = 5;
		player.getComponent<Sprite>().Play("Walk");
		player.getComponent<Sprite>().spriteFlip = SDL_FLIP_NONE;
	}

	if (Input.getKey(SDL_SCANCODE_A)) {

		player.getComponent<RigidBody>().velocity.x = -5;
		player.getComponent<Sprite>().Play("Walk");
		player.getComponent<Sprite>().spriteFlip = SDL_FLIP_HORIZONTAL;
	}

	if (Input.getKey(SDL_SCANCODE_W)) {

		player.getComponent<RigidBody>().velocity.y = 5;
		player.getComponent<Sprite>().Play("Walk");
	}

	if (Input.getKey(SDL_SCANCODE_S)) {

		player.getComponent<RigidBody>().velocity.y = -5;
		player.getComponent<Sprite>().Play("Walk");
	}

	if (!Input.getKey(SDL_SCANCODE_S) && !Input.getKey(SDL_SCANCODE_A) && !Input.getKey(SDL_SCANCODE_D) && !Input.getKey(SDL_SCANCODE_W)) {

		player.getComponent<Sprite>().Play("Idle");
	}


	for (auto cc : colliders) {
		
		Collision::AABB(player.getComponent<Collider>(), *cc);
	}
	
}

auto& tiles(manager.getGroup(gMap));
auto& players(manager.getGroup(gPlayers));
auto& enemies(manager.getGroup(gEnemies));

void Game::render()
{
	SDL_RenderClear(renderer);

	for (auto& t : tiles) {
		
		t->draw();
	}
	for (auto& p : players) {

		p->draw();
	}
	for (auto& e : enemies) {

		e->draw();
	}

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::AddTile(int srcX, int srcY, int xPos, int yPos) {

	auto& tile(manager.addEntity());
	tile.addComponent<Tile>(srcX, srcY, xPos, yPos, mapFile);
	tile.addGroup(gMap);
}