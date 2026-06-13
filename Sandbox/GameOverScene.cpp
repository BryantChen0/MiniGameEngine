#include "GameOverScene.h"
#include "../System/PhysicalSystem.h"
#include "../System/InputSystem.h"
#include "../System/RenderSystem.h"
#include "../Core/Object.h"
#include "iostream"
#include <SDL_ttf.h>

GameOverScene::GameOverScene(RenderSystem& renderSystem)
    :renderer(renderSystem)
{};

void GameOverScene::update(float dt) {}

void GameOverScene::render() {
    TTF_Font* font = TTF_OpenFont("assets/fonts/arial.ttf", 48);
    if (!font) {
        printf("Font load failed: %s\n", TTF_GetError());
        return;
    }

    SDL_Color black = { 0, 0, 0, 255 };

    SDL_Surface* surface = TTF_RenderText_Solid(
        font,
        "GAME OVER",
        black
    );

    if (!surface) {
        printf("surface error: %s\n", TTF_GetError());
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(
        renderer.getRenderer(),
        surface
    );

    SDL_FreeSurface(surface);

    SDL_Rect rect = { 300, 200, 300, 80 };

    SDL_RenderCopy(renderer.getRenderer(), texture, nullptr, &rect);

    SDL_DestroyTexture(texture);
}