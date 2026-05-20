#ifndef MINIGAMEENGINE_OBJECT_H
#define MINIGAMEENGINE_OBJECT_H
#include "Math/Vector2.h"
//数据类，用于记录当前游戏对象的变化

class Object {
public:
    Vector2 position;
    Vector2 velocity;

    //用户的键鼠输入
    void input();
    //根据时间t的变化，来更新当前时间的位置变动
    void update(float dt);
    //游戏的渲染结果
    void render();
};


#endif //MINIGAMEENGINE_OBJECT_H
