#include "GameScene.h"
#include "System/PhysicalSystem.h"
#include "System/InputSystem.h"
#include "System/RenderSystem.h"
#include "Core/Object.h"
#include "iostream"
using namespace std;

GameScene::GameScene()
    : testObj({ 80, 40 }, { 0, 300 }, { 0, 0 })
    , ground({ 800, 200 }, { 0, 500 }, { 0, 0 })
{}

void GameScene::update(float dt, InputSystem& input, PhysicalSystem& physicalSystem){
    if (input.isKeyHeld(SDL_SCANCODE_RIGHT)) testObj.velocity.x = 100;
    if (input.isKeyHeld(SDL_SCANCODE_LEFT))  testObj.velocity.x = -100;
    if (input.isKeyHeld(SDL_SCANCODE_UP))  testObj.velocity.y = -100;

    physicalSystem.moveObj(testObj, dt);
    physicalSystem.applyGravity(testObj, dt);
    if (physicalSystem.checkCollision(testObj, ground)) {
        gameOver = true;
    }
}

void GameScene::render(RenderSystem& render){
    render.draw(testObj, { 0,0,0,255 });
    render.draw(ground, { 0,0,0,255 });
}

bool GameScene::isDead() {
    return gameOver;
}
