#pragma once
#include "System/SceneSystem.h"
#include "Core/Object.h"

class InputSystem;
class PhysicalSystem;
class RenderSystem;
class ImageSystem;

class GameScene : public IScene {
private:
    Object testObj;
    Object ground;
    bool gameOver = false;
    InputSystem& input;
    PhysicalSystem& physical;
    RenderSystem& renderer;
    ImageSystem& image;
public:
    GameScene(InputSystem& inputSystem, PhysicalSystem& physicalSystem, RenderSystem& renderSystem, ImageSystem& imageSystem);
    void update(float dt) override;
    void render() override;
    void loadImage();
    bool isDead();
    ~GameScene() override = default;
};