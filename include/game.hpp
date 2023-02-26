#pragma once

#include "field.hpp"

class Game
{
private:
    Window* window;
    Field* field;

public:
    Game(int cols, int rows, int cell_size);
    ~Game();

    void run();
};