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

	Sprite(const char* path, int nFrames, int mSpeed) {


		animated = true;
		frames = nFrames;
		speed = mSpeed;

		setTexture(path);
	}

	~Sprite() {

		SDL_DestroyTexture(texture);
	}



	void setTexture(const char* path) {
		texture = TextureManager::LoadTexture(path);
	}

	void init() override {

		transform = &entity->getComponent<Transform>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
		destRect.h = destRect.w = 64;
	}

	void update() override {

		if (animated)
		{
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}

		destRect.x = (int)transform->position.x;
		destRect.y = (int)transform->position.y;
		destRect.w = transform->width * transform->scale.x;
		destRect.h = transform->height * transform->scale.y;

	}

	void draw() override {

		TextureManager::Draw(texture, srcRect, destRect);
	}


private:
	Transform* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

	bool animated = false;
	int frames = 0;
	int speed = 100;

};