#include "GameScene.h"
#include "Player.h"
#include "../System/PhysicalSystem.h"
#include "../System/InputSystem.h"
#include "../System/RenderSystem.h"
#include "../System/ImageSystem.h"
#include "../Core/Object.h"
#include "iostream"

GameScene::GameScene(InputSystem& inputSystem, PhysicalSystem& physicalSystem, RenderSystem& renderSystem, ImageSystem& imageSystem)
    : player(inputSystem, physicalSystem, { 80, 40 }, { 0, 0 }, { 0, 0 }),
    ground({ 800, 200 }, { 0, 500 }, { 0, 0 }),
    input(inputSystem),
    physical(physicalSystem),
    renderer(renderSystem),
    image(imageSystem)
    //构造函数初始化列表（Constructor Initialization List）
{
}

void GameScene::update(float dt){
    player.update(dt);
    if (physical.checkCollision(player, ground)) {
        gameOver = true;
    }
}

void GameScene::render(){
    renderer.draw(player, { 0,0,0,255 });
    renderer.draw(ground, { 0,0,0,255 });
}

void GameScene::loadImage()
{
    bool ok1 = image.LoadTexture("testObj", "testObj.png", renderer);

    bool ok2 = image.LoadTexture("ground", "ground.png", renderer);

    if (!ok1 || !ok2)
    {
        SDL_Log("load image failed");
        return;
    }

    player.texture =
        image.GetTexture("testObj");

    ground.texture =
        image.GetTexture("ground");
}

bool GameScene::isDead() {
    return gameOver;
}

