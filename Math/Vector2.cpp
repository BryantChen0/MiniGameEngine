#include "Vector2.h"

Vector2 Vector2::operator+(const Vector2& other) const {
    return {x + other.x, y + other.y};
}

Vector2 Vector2::operator*(float scalar) const {
    return {x * scalar, y * scalar};
}

Vector2 Vector2::operator-(const Vector2& other) const{
    return {x - other.x, y - other.y};
}

float Vector2::length() const {
    return
}