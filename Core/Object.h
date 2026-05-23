#pragma once
#include "../Math/Vector2.h"
#include <SDL2/SDL.h>
//数据类，用于记录当前游戏对象的变化

class Object {
public:
    Vector2 position;
    Vector2 velocity;

    //根据时间t的变化，来更新当前时间的位置变动
    void update(float dt);
};

