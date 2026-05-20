#include "Vector2.h"
#include "Math.h"

Vector2 Vector2::operator+(const Vector2& other) const {
    return {x + other.x, y + other.y};
}

Vector2 Vector2::operator*(float scalar) const {
    return {x * scalar, y * scalar};
}

Vector2 Vector2::operator-(const Vector2& other) const{
    return {x - other.x, y - other.y};
}

double Vector2::length() const {
    return Math::pow((Math::pow(x,2) + Math::pow(y,2)), 0.5);
}
