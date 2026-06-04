#pragma once
#include "../Math/Vector2.h"
#include <SDL2/SDL.h>
#include <SDL_image.h>
//数据类，储存对象的数据

class Object {
private:
public:
    Vector2 position = {0,0};
    Vector2 velocity = { 0,0 };
    Vector2 size = { 0,0 };
    SDL_Texture* texture;

    Object(Vector2 s, Vector2 p, Vector2 v);
};

