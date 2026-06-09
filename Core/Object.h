#pragma once
#include "../Math/Vector2.h"
#include "Collider.h"
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <vector>
//数据类，储存对象的数据

class Object {
private:
public:
    Vector2 position = {0,0};
    Vector2 velocity = { 0,0 };
    Vector2 rendersize = { 0,0 };
    SDL_Texture* texture;
    //这里需要明确一件事，游戏物体的碰撞体积和绘制体积并不是一回事
    //碰撞体的大小应该自己单独定义，同时这也给予了何种方式的碰撞的不同
    //总之需要明确的是，绘制体积是玩家看到的大小，但是碰撞体积是规则判断时候会用上的东西
    std::vector<Collider> colliders;

    Object(Vector2 s, Vector2 p, Vector2 v);
};

