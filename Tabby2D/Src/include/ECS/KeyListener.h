#pragma once
#include "Components.h"
#include "../Game.h"

class KeyListener : public Component {

public:

	bool getKey(SDL_Scancode key) {
		return state[key];
	}

	bool getKeyDown(SDL_Scancode key) {

		
		
	}

	void update() override {
		
	}

private:

	Uint8* output;
	const Uint8* state = SDL_GetKeyboardState(nullptr);
};