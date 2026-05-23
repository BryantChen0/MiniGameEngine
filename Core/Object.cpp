#include "Object.h"
#include <iostream>
#include <SDL2/SDL.h>

void Object::update(float dt){
    position = position + velocity * dt;
}