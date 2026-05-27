#include "Core/Object.h"
#include "System/InputSystem.h"
#include "System/RenderSystem.h"
#include "System/PhysicalSystem.h"
#include "iostream"
#include <SDL2/SDL.h>
using namespace std;

void resolveCollision(Object& a, Object& b){
    //获取中心点
    float aCenterX = (a.position.x + a.size.x)/2;
    float aCenterY = (a.position.y + a.size.y)/2;
    float bCenterX = (b.position.x + b.size.x)/2;
    float bCenterY = (b.position.y + b.size.y)/2;

    //计算中心点的距离
    float dx = bCenterX - aCenterX;
    float dy = bCenterY - aCenterY;

    //计算overlap的长度
    float overlapX = ((a.size.x / 2) + (b.size.x / 2)) - abs(dx);
    float overlapY = ((a.size.y / 2) + (b.size.y / 2)) - abs(dy);

    //overlap比较少的方向代表其是最近进入的方向或者说最应该向外推的方向
    if (overlapX < overlapY) {
        if (dx > 0) a.position.x -= overlapX;
        else a.position.x += overlapX;
        a.velocity.x = 0;
    }
    else {
        if (dy > 0) {
            //特殊情况，因为从上向下掉，会到达地面，而在地面上的时候，重力加速度不会对物体造成影响
            a.position.y -= overlapY;
            a.onGround = true;
        }
        else a.position.y += overlapY;
        a.velocity.y = 0;
    }
}

int main(){
    //游戏测试类初始化
    Object testObj;
    testObj.position = { 0, 300 };
    testObj.size = { 80, 40 };
    Object ground;
    ground.position = { 0,400 };
    ground.size = { 800, 200 };


    //输入系统类初始化
    InputSystem input;
    
    //初始化SDL2窗口
    //从抽象的角度来讲，窗口不应该归于渲染系统，他应该是主程序的运行窗口，所以不放到渲染系统下
    SDL_Init(SDL_INIT_VIDEO);//初始化SDL
    SDL_Window* window = SDL_CreateWindow(//创建窗口
        "Mini2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600, 0);
    
    //渲染系统类初始化
    RenderSystem render(window);

    //物理系统类初始化
    PhysicalSystem physicalSystem;

    //游戏主循环的配置
    bool running = true;
    Uint32 lastTime = SDL_GetTicks();//SDL的真实时间函数

    //游戏主循环
    while(running){
        //真实的时间变化
        Uint32 nowTime = SDL_GetTicks();
        float dt = (nowTime - lastTime) / 1000.0f;
        lastTime = nowTime;

        //输入
        input.update();
        if (input.isKeyHeld(SDL_SCANCODE_RIGHT)) testObj.velocity.x = 100;
        if (input.isKeyHeld(SDL_SCANCODE_LEFT))  testObj.velocity.x = -100;
        if (input.isKeyHeld(SDL_SCANCODE_UP))  testObj.velocity.y = -100;
        if (input.quitRequested()) running = false;

        //更新数据
        physicalSystem.moveObj(testObj, dt);
        physicalSystem.applyGravity(testObj, dt);
        if (physicalSystem.checkCollision(testObj, ground)) 
            resolveCollision(testObj, ground);
        

        //渲染
        render.clear({ 255, 255, 255, 255 });
        render.draw(testObj, { 0, 0, 0, 255 });
        render.draw(ground, { 0, 0, 0, 255 });
        render.present();

    }

    //清理缓存
    render.shutDown();
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
