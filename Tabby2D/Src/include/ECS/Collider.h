#pragma once
#include "Components.h"
#include "../Collision.h"
#include <string>
#include "SDL.h"

class Collider : public Component {

public:
	
	SDL_Rect collider;
	std::string tag;

	Transform* transform;

	Collider() {
		tag = "default";
	}

	Collider(std::string tag) {
		this->tag = tag;
	}

	void init() {

		if (!entity->hasComponent<Transform>()) {
			entity->addComponent<Transform>();
		}

		transform = &entity->getComponent<Transform>();

		Game::colliders.push_back(this);
	}

	void update() override {

		collider.x = static_cast<int>(transform->position.x);
		collider.y = static_cast<int>(transform->position.y);
		collider.h = transform->height * transform->scale.y;
		collider.w = transform->width * transform->scale.x;


	}

private:

	bool colliding;
};