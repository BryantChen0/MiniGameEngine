#include "RenderSystem.h"

void RenderSystem::init(SDL_Window* window) {
    renderer = SDL_CreateRenderer(//创建渲染器
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
}

void RenderSystem::clear(SDL_Color color) {
    //窗口渲染
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);//改变渲染器颜色为对应颜色
    SDL_RenderClear(renderer);//使用渲染器作为橡皮擦，将整个缓存区擦成对应颜色
}

void RenderSystem::draw(Object obj, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect = {
    (int)obj.position.x,
    (int)obj.position.y,
    40, 40
    };
    SDL_RenderFillRect(renderer, &rect);
}

void RenderSystem::present() {
    SDL_RenderPresent(renderer);
}

void RenderSystem::shutdown() {
    SDL_DestroyRenderer(renderer);
}

SDL_Renderer* RenderSystem::getrenderer() {
    return renderer;
}