#include "Actor.h"
#include "Transform.h"
#include "Rigidbody.h"
#include <iostream>

int Actor::counter = 0;

Actor::Actor() {
	mId = counter++;
}

void Actor::Start() {
}

void Actor::Update(float deltaTime) {
	//std::cout << "actor:Update()" << std::endl;
	
	//update positions of actor and collider
	Transform* tf = static_cast<Transform*>(GetComponent(ComponentType::Transform));
	Rigidbody* rb = static_cast<Rigidbody*>(GetComponent(ComponentType::Rigidbody));
	
	//new position 
	Vector2 newPosition = tf->mPosition + rb->mVelocity * deltaTime;
	tf->mPosition = newPosition;
}

SDL_Rect Actor::createRectangle(Vector2& position, Vector2& scale) {
	return SDL_Rect {
		static_cast<int>(position.x - scale.x/2),
		static_cast<int>(position.y - scale.y/2),
		static_cast<int>(scale.x),
		static_cast<int>(scale.y)
	};
}

void Actor::Draw(SDL_Renderer* renderer) {
	Transform* tf = static_cast<Transform*>(GetComponent(ComponentType::Transform));
	SDL_Rect r = createRectangle(tf->mPosition, tf->mScale);

	// Set render color to blue ( rect will be rendered in this color )
	SDL_SetRenderDrawColor(renderer, 40, 122, 184, 255);

	// Render rect
	SDL_RenderFillRect(renderer, &r);
	
}

void Actor::AddComponent(Component* component) {
	mComponents.push_back(component);
}

Component* Actor::GetComponent(ComponentType type) {
	for (Component* comp : mComponents) {
		if (comp->mComponentType == type) {
			return comp;
		}
	}
	return nullptr;
}
