#pragma once
#include "Components.h"
#include "../TextureManager.h"
#include "SDL.h"

class Sprite : public Component {
public:

	Sprite() = default;
	Sprite(const char* path) {
		setTexture(path);
	}

	void setTexture(const char* path) {
		texture = TextureManager::LoadTexture(path);
	}

	void init() override {

		transform = &entity->getComponent<Transform>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		destRect.h = destRect.w = 64;
	}

	void update() override {

		destRect.x = (int)transform->position.x;
		destRect.y = (int)transform->position.y;
	}

	void draw() override {

		TextureManager::Draw(texture, srcRect, destRect);
	}


private:
	Transform* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

};