#pragma once
#include "Components.h"
#include "../Vector2.h"


class Transform : public Component {
public:

	Vector2 position;

	Transform() {
		position.x = 0.0f;
		position.y = 0.0f;
	}

	Transform(float x, float y) {
		position.x = x;
		position.y = y;
	}

	void init() override {

	}


	void update() override {
		
	}
};