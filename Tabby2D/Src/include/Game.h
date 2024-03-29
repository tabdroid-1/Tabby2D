#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>

class Collider;

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	bool running() { return isRunning; }
	void render();
	void clean();

	static void AddTile(int srcX, int srcY, int xPos, int yPos);
	static SDL_Renderer* renderer;
	static SDL_Event event;
	static std::vector<Collider*> colliders;
	static SDL_Rect camera;
private:
	bool isRunning = false;
	int cnt = 0;
	SDL_Window *window;
};








