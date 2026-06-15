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
    ~UIText();
};