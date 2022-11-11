#pragma once
#include "Components.h"
#include "ECS.h"
#include "Transform.h"
#include "Sprite.h"
#include "SDL.h"


class Tile : public Component {

public:

	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

	Tile() = default;

	~Tile() {
		
		SDL_DestroyTexture(texture);

	}

	Tile(int srcX, int srcY, int xPos, int yPos, const char* path) {

		texture = TextureManager::LoadTexture(path);

		srcRect.x = srcX;
		srcRect.y = srcY;
		srcRect.w = srcRect.h = 32;

		destRect.x = xPos;
		destRect.y = yPos;
		destRect.w = destRect.h = 64;
	}

	void draw() override {

		TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
	}

};