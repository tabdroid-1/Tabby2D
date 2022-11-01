#pragma once
#include "Components.h"
#include "ECS.h"
#include "Transform.h"
#include "Sprite.h"
#include "SDL.h"


class Tile : public Component {

public:
	Transform* transform;
	Sprite* sprite;

	SDL_Rect tileRect;
	char* path;
	int tileID;

	Tile() = default;

	Tile(int x, int y, int w, int h, int id) {

		tileRect.x = x;
		tileRect.y = y;
		tileRect.w = w;
		tileRect.h = h;
		tileID = id;

		switch (tileID) {

		case 0:
			path = "assets/textures/dirt.png";
			break;
		case 1:
			path = "assets/textures/grass.png";
			break;
		case 2:
			path = "assets/textures/water.png";
			break;
		default:
			break;
		}

		
	}

	void init() override {

		entity->addComponent<Transform>((float)tileRect.x, (float)tileRect.y, tileRect.w, tileRect.h, Vector2(1, 1));
		transform = &entity->getComponent<Transform>();

		entity->addComponent<Sprite>(path);
		sprite = &entity->getComponent<Sprite>();
	}

};