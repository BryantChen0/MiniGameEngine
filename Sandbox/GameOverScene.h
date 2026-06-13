#pragma once
#include "../System/SceneSystem.h"
#include "../Core/Object.h"

class InputSystem;
class PhysicalSystem;
class RenderSystem;

class GameOverScene : public IScene {
private:
    RenderSystem& renderer;
public:
    GameOverScene(RenderSystem& renderSystem);
    void update(float dt) override;
    void render() override;
    ~GameOverScene() override = default;
};