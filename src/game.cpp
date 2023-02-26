#include "game.hpp"

Game::Game(int cols, int rows, int cell_size)
{
    window = new Window("Game of Life", cell_size * cols, cell_size * rows);
    field = new Field(cols, rows, cell_size);
}

Game::~Game()
{
    delete window;
}

void Game::run()
{
    while (!window->should_close)
    {
        while (window->pollEvents())
        {
            if (window->hasEvent(SDL_QUIT))
                window->close();
        }

        field->update();
        window->clear();
        field->draw(window);
        window->update();
    }
}