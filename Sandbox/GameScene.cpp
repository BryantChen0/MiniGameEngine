#include "GameScene.h"
#include "Player.h"
#include "Pipe.h"
#include "../System/PhysicalSystem.h"
#include "../System/InputSystem.h"
#include "../System/RenderSystem.h"
#include "../System/ImageSystem.h"

#include "../Core/Object.h"
#include "iostream"

GameScene::GameScene(InputSystem& inputSystem, PhysicalSystem& physicalSystem, RenderSystem& renderSystem, ImageSystem& imageSystem, Vector2 screenSize)
    : player(inputSystem, { 80, 40 }, { 0, 200 }, { 0, 0 }),
    input(inputSystem),
    physical(physicalSystem),
    renderer(renderSystem),
    image(imageSystem)
    //构造函数初始化列表（Constructor Initialization List）
{
    screenWidth = screenSize.x;
    screenHeight = screenSize.y;
}

void GameScene::spawnPipe() {
    //rand() % range + min这个随机数公式的范围是[min, min + range - 1]
    float gapY = rand() % ((int)screenHeight - 200) + 100;

    pipes.spawn(
        gapY,
        200.0f,
        Vector2{ screenWidth, screenHeight },
        Vector2{ 160, screenHeight },
        Vector2{ screenWidth, 0 },
        Vector2{ -50, 0 },
        image.GetTexture("topPipe"),
        image.GetTexture("bottomPipe")
    );
}

void GameScene::update(float dt){
    player.update(dt);
    physical.applyGravity(player, dt);
    physical.moveObj(player, dt);

    //管道生成
    pipeSpawnTimer += dt;
    if (pipeSpawnTimer >= pipeSpawnInterval)
    {
        spawnPipe();
        pipeSpawnTimer = 0;
    }

    //移动管道
    for (auto& pipe : pipes.getObjects())
    {
        physical.moveObj(pipe, dt);
    }

    pipes.update(dt);

    for (auto& pipe : pipes.getObjects())
    {
        //碰撞检测
        if (physical.checkCollision(player, pipe))
        {
            gameOver = true;
        }
        //得分机制
        if (!pipe.scored && player.position.x > pipe.position.x)
        {
            score++;
            pipe.scored = true;
        }
    }


    //清除离开屏幕的管道
    pipes.removeDead();
}

void GameScene::render(){
    renderer.draw(player);
    for (auto& pipe : pipes.getObjects())
    {
        renderer.draw(pipe.topPipe);
        renderer.draw(pipe.bottomPipe);
    }

}

void GameScene::loadImage()
{
    bool ok1 = image.LoadTexture("player", "player.png", renderer);
    bool ok2 = image.LoadTexture("topPipe", "topPipe.png", renderer);
    bool ok3 = image.LoadTexture("bottomPipe", "bottomPipe.png", renderer);

    if (!ok1 || !ok2 || !ok3)
    {
        SDL_Log("load image failed");
        return;
    }

    player.texture =
        image.GetTexture("player");
}

void GameScene::reset() {
    gameOver = false;
    score = 0;

    player.position = { 80, 200 };
    player.velocity = { 0, 0 };

    pipes.clear();

    pipeSpawnTimer = 0;
}
