#include "window.hpp"

Window::Window(const char *title, int width, int height) : should_close(false)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

bool Window::pollEvents()
{
    return SDL_PollEvent(&event) != 0;
}

bool Window::hasEvent(SDL_EventType type)
{
    return event.type == type;
}

void Window::changeColor(int color[3])
{
    SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], 255);
}

void Window::clear()
{
    changeColor(background);
    SDL_RenderClear(renderer);
}

void Window::update()
{
    SDL_RenderPresent(renderer);
}

void Window::close()
{
    should_close = true;
}

unsigned int Window::getTicks()
{
    return SDL_GetTicks();
}

void Window::drawRect(int x, int y, int width, int height, int color[3])
{
    changeColor(color);
    SDL_Rect rect{x, y, width, height};
    SDL_RenderFillRect(renderer, &rect);
}