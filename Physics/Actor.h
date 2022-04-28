#pragma once
#include <vector>
#include "Component.h"
#include <SDL.h>
#include "Vector2.h"
class Actor {
	int mId;
	static int counter;

	SDL_Rect createRectangle(Vector2&, Vector2&); //we can shift this to some other class
public:
	std::vector<Component*> mComponents;

	Actor();
	void Start();
	void Update(float deltaTime);
	void Draw(SDL_Renderer*);
	void AddComponent(Component*);
	Component* GetComponent(ComponentType);
};

