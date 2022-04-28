#include "Vector2.h"
#include <math.h>

Vector2::Vector2(float pX, float pY) : x(pX), y(pY) {
}

Vector2 Vector2::Zero() {
    return Vector2(0.0f, 0.0f);
}

float Vector2::Magnitude() const {
    return sqrt(x*x + y*y);
}

Vector2 Vector2::operator*(float scalar) {
    return Vector2(this->x * scalar, this->y * scalar);
}

Vector2 Vector2::operator+(Vector2 other) {
    return Vector2(this->x + other.x, this->y + other.y);
}
