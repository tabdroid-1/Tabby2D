#pragma once
#include "SDL.h"


class Collider;

class Collision {

public:

	static bool AABB(const SDL_Rect& recA, const SDL_Rect& rec);  // Axis Align Bounding Box
	static bool AABB(const Collider& colA, const Collider& colB);
};