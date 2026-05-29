#include "Core/Object.h"
#include "System/InputSystem.h"
#include "System/RenderSystem.h"
#include "System/PhysicalSystem.h"
#include "System/SceneSystem.h"
#include "GameScene.h"
#include "GameOverScene.h"
#include "iostream"
#include <SDL2/SDL.h>
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

    //游戏场景类初始化
    GameScene gameScene;
    GameOverScene gameOverScene;
    SceneManager sceneManager;
    sceneManager.switchScene(&gameScene);

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
        render.present();

    }

    //清理缓存
    render.shutDown();
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
