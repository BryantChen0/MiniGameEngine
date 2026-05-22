#include "Core/Object.h"
#include "System/InputSystem.h"
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
    
    //初始化SDL2
    SDL_Init(SDL_INIT_VIDEO);//初始化SDL
    SDL_Window* window = SDL_CreateWindow(//创建窗口
        "Mini2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(//创建渲染器
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
        );

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

        //窗口渲染
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);//改变渲染器颜色为黑色
        SDL_RenderClear(renderer);//使用渲染器作为橡皮擦，将整个缓存区擦成黑色

        //测试类渲染
        testObj.render(renderer);
        SDL_RenderPresent(renderer);//输出渲染结果

    }

    //清理缓存
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
