#pragma once

#include "Components.h"
#include "../Vector2.h"

class RigidBody : public Component {

public:

	RigidBody() {
		velocity.x = 0;
		velocity.y = 0;

		friction = 1;
	}

	RigidBody(float friction) {
		velocity.x = 0;
		velocity.y = 0;

		this->friction = friction;
	}


	Vector2 velocity;	// Entity velocity
	float friction;		// DON'T DECLARE IT MORE THAN 1!


	void init() override {

		transform = &entity->getComponent<Transform>();
	}

	void update() override {

		velocityHandler();
	}






private:

	Transform* transform;

	void velocityHandler() {

		transform->position += Vector2(velocity.x, -velocity.y);

		velocity -= Vector2(velocity.x * friction, velocity.y * friction);
	}
};