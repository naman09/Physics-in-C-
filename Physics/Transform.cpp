#include "Transform.h"
#include "Vector2.h"

Transform::Transform(Vector2& pos, Vector2& scale) : Component(ComponentType::Transform), 
	mPosition(pos),
	mScale(scale) {}
