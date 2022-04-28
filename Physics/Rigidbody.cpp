#include "Rigidbody.h"

Rigidbody::Rigidbody(float mass, Vector2 initialVelocity) : Component(ComponentType::Rigidbody),
	mMass(mass),
	mVelocity(initialVelocity),
	mAcceleration(Vector2::Zero()) {}

void Rigidbody::AddForce(Vector2& force, float deltaTime) {

}
