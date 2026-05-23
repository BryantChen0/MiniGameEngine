#include "Core/Object.h"
#include "System/InputSystem.h"
#include "System/RenderSystem.h"
#include "iostream"
#include <SDL2/SDL.h>
using namespace std;

int main(){
    //游戏测试类初始化
    Object testObj;
    testObj.position = { 0, 300 };
    testObj.velocity = { 0, 0 };

    //输入系统类初始化
    InputSystem input;
    
    //初始化SDL2窗口
    //从抽象的角度来讲，窗口不应该归于渲染系统，他应该是主程序的运行窗口，所以不放到渲染系统下
    SDL_Init(SDL_INIT_VIDEO);//初始化SDL
    SDL_Window* window = SDL_CreateWindow(//创建窗口
        "Mini2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600, 0);
    
    //渲染系统类初始化
    RenderSystem render;
    render.init(window);

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
        if (input.isKeyHeld(SDL_SCANCODE_RIGHT)) testObj.velocity.x = 200;
        if (input.isKeyHeld(SDL_SCANCODE_LEFT))  testObj.velocity.x = -200;
        if (input.quitRequested()) running = false;

        //更新数据
        testObj.update(dt);

        //渲染
        render.clear({ 255, 255, 255, 255 });
        render.draw(testObj, { 0, 0, 0, 255 });
        render.present();

    }

    //清理缓存
    render.shutdown();
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
