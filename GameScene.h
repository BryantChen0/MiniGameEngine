#pragma once
#include "System/SceneSystem.h"
#include "Core/Object.h"

class InputSystem;
class PhysicalSystem;
class RenderSystem;

class GameScene : public IScene {
private:
    Object testObj;
    Object ground;
    bool gameOver = false;
public:
    GameScene();
    void update(float dt, InputSystem& input, PhysicalSystem& physicalSystem) override;
    void render(RenderSystem& render) override;
    bool isDead();
    ~GameScene() override = default;
};