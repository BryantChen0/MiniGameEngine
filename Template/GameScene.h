#pragma once
#include "../System/SceneSystem.h"
#include "../Core/Object.h"
#include "Player.h"

class InputSystem;
class PhysicalSystem;
class RenderSystem;
class ImageSystem;

class GameScene : public IScene {
private:
    Player player;
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