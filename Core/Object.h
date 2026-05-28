#pragma once
#include "../Math/Vector2.h"
#include <SDL2/SDL.h>
//数据类，用于记录当前游戏对象的数据

class Object {
private:
public:
    Vector2 position = {0,0};
    Vector2 velocity = { 0,0 };
    Vector2 size = { 0,0 };

    Object(Vector2 s, Vector2 p, Vector2 v);
};

