#pragma once
enum class ComponentType {
	Transform,
	Rigidbody,
	Collider
};
class Component {
public:
	ComponentType mComponentType;

	Component(ComponentType);
};

