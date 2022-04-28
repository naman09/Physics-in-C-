#pragma once
class Vector2 {
public:
	float x;
	float y;

	Vector2(float, float);
	static Vector2 Zero();
	float Magnitude() const;
	//float UnitVector() const;

	Vector2 operator * (float scalar);
	Vector2 operator + (Vector2 other);
};

