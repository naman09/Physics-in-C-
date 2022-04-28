#pragma once
#include "Component.h"
#include "Vector2.h"
class Rigidbody : public Component {
public:
	float mMass;
	Vector2 mVelocity;
	Vector2 mAcceleration;

	Rigidbody(float mass, Vector2 initialVelocity);
	void AddForce(Vector2& force, float deltaTime);

};

