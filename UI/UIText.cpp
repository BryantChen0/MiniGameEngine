#include "UIText.h"
#include "../System/RenderSystem.h"
#include <SDL_ttf.h>
#include <string>

UIText::UIText(RenderSystem& renderSystem, const std::string& s, int x, int y, int length, int width)
	:renderer(renderSystem),
    text(s)
{
    rect = { x, y, length, width };

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

    texture =
        SDL_CreateTextureFromSurface(
            renderer.getRenderer(),
            surface
        );

    SDL_FreeSurface(surface);
}

void UIText::render() {
    SDL_RenderCopy(renderer.getRenderer(), texture, nullptr, &rect);
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