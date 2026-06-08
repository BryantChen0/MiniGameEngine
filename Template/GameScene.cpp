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

    //这个和push的差别在于，其直接构造对象，但是push需要临时对象进行拷贝或者移入其中
    pipes.emplace_back(
        screenHeight / 2,
        100.0f,
        screenSize,
        Vector2{ 160, screenHeight },
        Vector2{ screenWidth, 0 },
        Vector2{ -50, 0 }
    );
}

void GameScene::spawnPipe() {
    //rand() % range + min这个随机数公式的范围是[min, min + range - 1]
    float gapY = rand() % ((int)screenHeight - 200) + 100;

    pipes.emplace_back(
        gapY,
        100.0f,
        Vector2{ screenWidth, screenHeight },
        Vector2{ 160, screenHeight },
        Vector2{ screenWidth, 0 },
        Vector2{ -50, 0 }
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
    for (auto& pipe : pipes)
    {
        physical.moveObj(pipe, dt);
        pipe.update(dt);
    }

    //碰撞检测
    for (auto& pipe : pipes)
    {
        if (physical.checkCollision(player, pipe.topPipe)
            || physical.checkCollision(player, pipe.bottomPipe))
        {
            gameOver = true;
        }
    }

    //清除离开屏幕的管道
    for (int i = pipes.size() - 1; i >= 0; i--) {
        if (pipes[i].isOutOfScreen()) {
            pipes.erase(pipes.begin() + i);
        }
    }
}

void GameScene::render(){
    renderer.draw(player, { 0,0,0,255 });
    for (auto& pipe : pipes)
    {
        renderer.draw(pipe.topPipe, { 0,0,0,255 });
        renderer.draw(pipe.bottomPipe, { 0,0,0,255 });
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

    pipes.back().topPipe.texture =
        image.GetTexture("topPipe");

    pipes.back().bottomPipe.texture =
        image.GetTexture("bottomPipe");
}

bool GameScene::isDead() {
    return gameOver;
}


