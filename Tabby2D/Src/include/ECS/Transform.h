#pragma once
#include "Components.h"
#include "../Vector2.h"


class Transform : public Component {
public:

	Vector2 position;

	Vector2 scale = Vector2(1, 1);
	int width = 32;
	int height = 32;
	

	Transform() {
		position.x = 0.0f;
		position.y = 0.0f;
	}

	Transform(Vector2 scale) {
		this->scale = scale;
	}

	Transform(float x, float y) {
		position.x = x;
		position.y = y;
	}

	Transform(float x, float y, int width, int height, Vector2 scale) {
		position.x = x;
		position.y = y;

		this->width = width;
		this->height = height;

		this->scale = scale;
	}

	void init() override {

	}


	void update() override {
		
	}
};