#pragma once
#include "Game.h"
#pragma once

#include "Game.h"

class KeyListener {

public:

	bool getKey(SDL_Scancode key) {
		return state[key];
	}

	bool getKeyDown(SDL_Scancode key) {

		if (Game::event.key.repeat = 0 && state[key]) {
			return true;
		}
		else {
			return false;
		}
	}


private:

	const Uint8* state = SDL_GetKeyboardState(nullptr);
};