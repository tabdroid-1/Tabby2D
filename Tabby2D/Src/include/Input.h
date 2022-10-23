#pragma once
#include "Game.h"

class Input {
public:

	bool getKey(SDL_Scancode key) {
		return state[key];
	}

	bool getKeyDown(SDL_Scancode key) {
		
		bool canTriger = true;

		if (canTriger && state[key]) {
			
			canTriger = false;
			return true;
		}
		else {
			false;
		}
	}

private:

	const Uint8* state = SDL_GetKeyboardState(nullptr);
};