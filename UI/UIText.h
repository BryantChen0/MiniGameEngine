#pragma once
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include <string>

class RenderSystem;

class UIText {
private:
    std::string text;
    RenderSystem& renderer;
    SDL_Rect rect;
    SDL_Texture* texture = nullptr;
    TTF_Font* font = nullptr;

public:
    UIText(RenderSystem& renderSystem, const std::string& s, int x, int y, int length, int width);
    void render();
    void setFont(std::string fontPath, int fontSize);
    void setTexture(std::string newText);
    void setText(std::string newText);
    UIText(const UIText&) = delete;
    UIText& operator=(const UIText&) = delete;
    ~UIText();
};