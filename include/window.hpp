#pragma once

#include "SDL2/SDL.h"

using namespace std;

class Window
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    int background[3] = {10, 10, 20};

public:
    bool should_close;

    Window(const char *title, int width, int height);
    ~Window();

    bool pollEvents();
    bool hasEvent(SDL_EventType type);

    void changeColor(int color[3]);
    void clear();
    void update();
    void close();

    void drawRect(int x, int y, int width, int height, int color[3]);

    unsigned int getTicks();
};