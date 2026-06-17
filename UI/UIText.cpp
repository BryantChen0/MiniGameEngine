#include "UIText.h"
#include "../System/RenderSystem.h"
#include <SDL_ttf.h>
#include <string>

UIText::UIText(RenderSystem& renderSystem, const std::string& s, int x, int y, int length, int width)
	:renderer(renderSystem),
    text(s)
{
    rect = { x, y, length, width };
    setFont("assets/fonts/arial.ttf", 48);
    setTexture(text);
}

void UIText::render() {
    SDL_RenderCopy(renderer.getRenderer(), texture, nullptr, &rect);
}

void UIText::setFont(std::string fontPath, int fontSize) {
    font = TTF_OpenFont(
        "assets/fonts/arial.ttf",
        48
    );

    if (!font) {
        printf(
            "Font load failed: %s\n",
            TTF_GetError()
        );
        return;
    }
}

void UIText::setTexture(std::string newText) {
    SDL_Color black = {
    0,0,0,255
    };

    SDL_Surface* surface =
        TTF_RenderText_Solid(
            font,
            text.c_str(),
            black
        );

    if (!surface) {
        printf(
            "surface error: %s\n",
            TTF_GetError()
        );
        return;
    }

    SDL_Texture* newTexture =
        SDL_CreateTextureFromSurface(
            renderer.getRenderer(),
            surface
        );

    SDL_FreeSurface(surface);

    texture = newTexture;
}

void UIText::setText(std::string newText) {
    if (newText == text)
        return;

    text = newText;

    if (texture)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }

    setTexture(text);
}

UIText::~UIText()
{
    if (texture) {
        SDL_DestroyTexture(texture);
    }

    if (font) {
        TTF_CloseFont(font);
    }
}