#include "Core/Object.h"
#include "System/InputSystem.h"
#include "System/RenderSystem.h"
#include "System/PhysicalSystem.h"
#include "System/SceneSystem.h"
#include "GameScene.h"
#include "GameOverScene.h"
#include "iostream"
#include <SDL2/SDL.h>
#include <SDL_image.h>

using namespace std;
// include的基本规则：能够少include的就少include，按照以下的优先级
// 如果private是一个类，需要include这个类的头文件
// 继承类需要include，因为其需要知道大小和逻辑
// 头文件不需要include，只需要让编译器知道有这个类就行
// 源文件需要include，因为其需要知道类的大小和实现的具体逻辑
// 如果当前文件只有引用和指针，一样不需要include，因为引用和指针本质上就是地址，其大小固定的

int main(){
    //输入系统类初始化
    InputSystem input;
    
    // 初始化SDL2窗口
    // 从抽象的角度来讲，窗口不应该归于渲染系统，他应该是主程序的运行窗口，所以不放到渲染系统下
    /*SDL2窗口初始化流程解释：
    使用SDL2本身自带的flag来启动SDL2系统的某个部分，比如SDL_INIT_VIDEO启动的就是SDL2的视频系统
    如果初始化成功，会返回非负二进制数，如果不成功，则会返回负数
    当系统启动初始化完成后，创建SDL_Window*指针指向创建的窗口类*/ 
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_Log("SDL 初始化失败: %s",
            SDL_GetError());
    }//初始化SDL
    SDL_Window* window = SDL_CreateWindow(//创建窗口
        "Mini2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600, 0);
    
    //渲染系统类初始化
    //RenderSystem render(window);
    SDL_Renderer* renderer =
        SDL_CreateRenderer(window, -1,
            SDL_RENDERER_ACCELERATED);

    //物理系统类初始化
    PhysicalSystem physicalSystem;

    //游戏场景类初始化
    GameScene gameScene;
    GameOverScene gameOverScene;
    SceneManager sceneManager;
    sceneManager.switchScene(&gameScene);

    //图片资源初始化
    /*流程解释：
    和窗口初始化差不多的流程，先用IMG_Init来初始化什么类型的图片支持
    因为图片类型使用flag来表示，所以如果初始化成功，IMG_Init就会返回这个图片类型的flag的二进制
    通过and逻辑运算符判断该类型初始化是否成功，如果不成功，因为两个flag是不同的二进制，就会为假*/
    int result = IMG_Init(IMG_INIT_PNG);
    if (!(result & IMG_INIT_PNG))
    {
        SDL_Log("SDL_image init failed: %s", IMG_GetError());
    }

    SDL_Log("result = %d", result);
    SDL_Log("%s", IMG_GetError());

    //测试
    SDL_Surface* surface = IMG_Load("test.png");
    //surface是一块存在CPU的像素内存，直接储存每个像素的颜色数据
    //优点是其可以随时更改每一个像素的颜色，缺点是其需要把每一个像素的数据传递给GPU用于渲染

    if (!surface)
    {
        SDL_Log("IMG_Load failed: %s",
            IMG_GetError());
    }

    SDL_Texture* texture =
        SDL_CreateTextureFromSurface(renderer, surface);
    //texture是GPU显存中的数据，GPU专门使用这种对象来进行绘制
    //优点是画的快，缺点则是其不能直接改像素的颜色
    SDL_FreeSurface(surface);

    SDL_RenderCopy(renderer, texture, NULL, NULL);


    //游戏主循环的配置
    bool running = true;
    Uint32 lastTime = SDL_GetTicks();//SDL的真实时间函数
    SDL_Event event;

    //游戏主循环
    while(running){
        //图片资源加载测试
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;
        }

        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer,
            texture,
            NULL,
            NULL);

        SDL_RenderPresent(renderer);
        /*//真实的时间变化
        Uint32 nowTime = SDL_GetTicks();
        float dt = (nowTime - lastTime) / 1000.0f;
        lastTime = nowTime;

        //输入
        input.update();
        if (input.quitRequested()) running = false;

        //更新当前场景数据
        sceneManager.update(dt, input, physicalSystem);
        if (gameScene.isDead())
        {
            sceneManager.switchScene(
                &gameOverScene
            );
        }

        //渲染
        render.clear({ 255, 255, 255, 255 });
        sceneManager.render(render);
        render.present();*/
        

    }

    //清理缓存
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    //render.shutDown();
    SDL_DestroyWindow(window);
    SDL_Quit();
    IMG_Quit();


    return 0;
}
