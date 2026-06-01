#pragma once
#include "Math.h"
#include <iostream>
//坐标数据结构
//这里使用struct，而不是class的原因是vector2是一个数学对象，也就是说
//如果它的数据被外部直接修改，也不会影响这个对象和它内部函数的逻辑
//但是如果对象的数据是基于某个规则的，也就是说这个数据如果被随意修改会破坏对于这个对象的定义
//那么就不能让外部直接修改这个数据，在这种情况下，就需要使用class将其变成无法让外部访问和修改的数据

struct Vector2 {
    float x, y;

    Vector2 Vector2::operator+(const Vector2& other) const {
        return { x + other.x, y + other.y };
    }

    Vector2 Vector2::operator*(float scalar) const {
        return { x * scalar, y * scalar };
    }

    Vector2 Vector2::operator-(const Vector2& other) const {
        return { x - other.x, y - other.y };
    }

    double Vector2::length() const {
        return Math::pow((Math::pow(x, 2) + Math::pow(y, 2)), 0.5);
    }
};