#pragma once
#include "Components.h"
#include "../Vector2.h"


class Transform : public Component {
public:

	Vector2 position;
	Vector2 velocity;

	Transform() {
		position.x = 0.0f;
		position.y = 0.0f;
	}

	Transform(float x, float y) {
		position.x = x;
		position.y = y;
	}

	void init() override {
		velocity.x = 0.0f;
		velocity.y = 0.0f;
	}


	void update() override {
		
		position += velocity;
	}
};