#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* renderer, int xPos, int yPos) {

	this->renderer = renderer;
	objTexture = TextureManager::LoadTexture(textureSheet, renderer);

	this->xPos = xPos;
	this->yPos = yPos;
}

void GameObject::Update() {

	xPos++;
	yPos++;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xPos;
	destRect.y = yPos;
	destRect.h = srcRect.h * 2;
	destRect.w = srcRect.w * 2;
}

void GameObject::Render() {
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}