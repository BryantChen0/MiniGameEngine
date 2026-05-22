#include "Object.h"
#include <iostream>
#include <SDL2/SDL.h>

void Object::update(float dt){
    position = position + velocity * dt;
}

void Object::render(SDL_Renderer* renderer) {
    //¿‡‰÷»æ
    SDL_Rect rect = {
        (int)position.x,
        (int)position.y,
        40, 40
    };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}