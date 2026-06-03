#include "GameScene.h"
#include "System/PhysicalSystem.h"
#include "System/InputSystem.h"
#include "System/RenderSystem.h"
#include "System/ImageSystem.h"
#include "Core/Object.h"
#include "iostream"

GameScene::GameScene(InputSystem& inputSystem, PhysicalSystem& physicalSystem, RenderSystem& renderSystem, ImageSystem& imageSystem)
    : testObj({ 80, 40 }, { 0, 0 }, { 0, 0 }),
    ground({ 800, 200 }, { 0, 500 }, { 0, 0 }),
    input(inputSystem),
    physical(physicalSystem),
    renderer(renderSystem),
    image(imageSystem)
{
}

void GameScene::update(float dt){
    if (input.isKeyHeld(SDL_SCANCODE_RIGHT)) testObj.velocity.x = 100;
    if (input.isKeyHeld(SDL_SCANCODE_LEFT))  testObj.velocity.x = -100;
    if (input.isKeyHeld(SDL_SCANCODE_UP))  testObj.velocity.y = -100;

    physical.moveObj(testObj, dt);
    physical.applyGravity(testObj, dt);
    if (physical.checkCollision(testObj, ground)) {
        gameOver = true;
    }
}

void GameScene::render(){
    renderer.draw(testObj, { 0,0,0,255 });
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

    testObj.texture =
        image.GetTexture("testObj");

    ground.texture =
        image.GetTexture("ground");
}

bool GameScene::isDead() {
    return gameOver;
}

