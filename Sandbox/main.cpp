#include "../Core/Window.h"
#include "../System/InputSystem.h"
#include "../System/RenderSystem.h"
#include "../System/PhysicalSystem.h"
#include "../System/SceneSystem.h"
#include "../System/ImageSystem.h"
#include "GameScene.h"
#include "GameOverScene.h"
#include "GameState.h"
#include "iostream"
#include <SDL_ttf.h>

using namespace std;
// include的基本规则：能够少include的就少include，按照以下的优先级
// 如果private是一个类，需要include这个类的头文件
// 继承类需要include，因为其需要知道大小和逻辑
// 头文件不需要include，只需要让编译器知道有这个类就行
// 源文件需要include，因为其需要知道类的大小和实现的具体逻辑
// 如果当前文件只有引用和指针，一样不需要include，因为引用和指针本质上就是地址，其大小固定的

//运行流程：
//1.创建SDL窗口
//2.创建场景管理器储存游戏开始的场景
//3.加载场景内的实体的数据
//4.通过图片加载类，为实体创建一个特定的图片
//5.渲染类基于实体的图片和数据在场景内绘制
//6.输入类和物理类同时更新实体的数据
//7.重复第5步和第6步直到达到某个切换场景管理器内储存的场景的条件



int main(){
    int windowLength = 800;
    int windowWidth = 600;
    // 初始化SDL2窗口
    Window window(
        "Mini2D",
        windowLength,
        windowWidth
    );

    if (TTF_Init() == -1) {
        printf("TTF_Init failed: %s\n", TTF_GetError());
    }

    //输入系统类初始化
    InputSystem inputSystem;

    //物理系统类初始化
    PhysicalSystem physicalSystem;
    
    //渲染系统类初始化
    RenderSystem renderSystem(window);

    //图片资源系统初始化
    ImageSystem imageSystem;

    //游戏场景类初始化
    GameState gameState;
    GameScene gameScene(inputSystem, physicalSystem, renderSystem, imageSystem, gameState, { 800, 600 });
    gameScene.loadImage();
    GameOverScene gameOverScene(inputSystem,renderSystem, gameState);
    SceneManager sceneManager;
    sceneManager.registerScene(
        gameScene.getID(),
        &gameScene
    );

    sceneManager.registerScene(
        gameOverScene.getID(),
        &gameOverScene
    );

    sceneManager.switchScene(
        gameScene.getID()
    );


    //游戏主循环的配置
    bool running = true;
    Uint32 lastTime = SDL_GetTicks();//SDL的真实时间函数;

    //游戏主循环
    while(running){
        //真实的时间变化
        Uint32 nowTime = SDL_GetTicks();
        float dt = (nowTime - lastTime) / 1000.0f;
        lastTime = nowTime;

        //输入
        inputSystem.update();
        if (inputSystem.quitRequested()) running = false;

        //场景切换
        sceneManager.update(dt);

        //渲染
        renderSystem.clear({ 255, 255, 255, 255 });
        sceneManager.render();
        renderSystem.present();
        
    }

    //清理缓存
    imageSystem.Clear();
    renderSystem.shutDown();

    return 0;
}
