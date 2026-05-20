#include "Object.h"
#include <iostream>

void Object::input() {}

void Object::update(float dt){
    position = position + velocity * dt;
}

void Object::render() {
    std::cout
    << "current position is "
    << this->position.x << ","
    << this->position.y << "\n";
}