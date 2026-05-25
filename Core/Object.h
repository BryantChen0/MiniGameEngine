#pragma once
#include "../Math/Vector2.h"
#include <SDL2/SDL.h>
//数据类，用于记录当前游戏对象的数据

class Object {
private:
public:
    Vector2 position;
    Vector2 velocity;
    Vector2 size;

    Object();
};

