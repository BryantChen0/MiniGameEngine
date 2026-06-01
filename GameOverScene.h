#pragma once
#include "System/SceneSystem.h"
#include "Core/Object.h"

class InputSystem;
class PhysicalSystem;
class RenderSystem;

class GameOverScene : public IScene {
public:
    GameOverScene();
    void update(float dt, InputSystem& input, PhysicalSystem& physicalSystem) override;
    void render(RenderSystem& render) override;
    ~GameOverScene() override = default;
};