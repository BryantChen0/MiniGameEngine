#include <SDL2/SDL.h>
#include<cstring>
#include "InputSystem.h"

void InputSystem::update() {//更新输入队列;
	//内存复制，将这一帧的输入内容储存到上一帧
    if (currentKeys != nullptr) {
        memcpy(prevKeys, currentKeys, SDL_NUM_SCANCODES);
    }

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quit = true;
        }
    }

    currentKeys = SDL_GetKeyboardState(NULL);
}

bool InputSystem::isKeyHeld(SDL_Scancode key) {
    if (currentKeys == nullptr) return false;
    return currentKeys[key];
}

bool InputSystem::isKeyPressed(SDL_Scancode key) {
    if (currentKeys == nullptr) return false;
    return !prevKeys[key] && currentKeys[key];
}

bool InputSystem::isKeyReleased(SDL_Scancode key) {
    if (currentKeys == nullptr) return false;
    return prevKeys[key] && !currentKeys[key];
}

bool InputSystem::quitRequested() {
    return quit;
}