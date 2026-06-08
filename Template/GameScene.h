#pragma once
#include "../System/SceneSystem.h"
#include "Player.h"
#include "Pipe.h"
#include "../Core/Object.h"
#include <vector>

class InputSystem;
class PhysicalSystem;
class RenderSystem;
class ImageSystem;

class GameScene : public IScene {
private:
    Player player;
    std::vector<Pipe> pipes;
    float screenWidth;
    float screenHeight;
    bool gameOver = false;
    float pipeSpawnTimer = 0.0f;
    float pipeSpawnInterval = 2.0f;
    InputSystem& input;
    PhysicalSystem& physical;
    RenderSystem& renderer;
    ImageSystem& image;
public:
    GameScene(InputSystem& inputSystem, PhysicalSystem& physicalSystem, RenderSystem& renderSystem, ImageSystem& imageSystem, Vector2 screenSize);
    void spawnPipe();
    void update(float dt) override;
    void render() override;
    void loadImage();
    bool isDead();
    ~GameScene() override = default;
};