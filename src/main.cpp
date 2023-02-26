#include "game.hpp"

#define CELL_SIZE 8
#define COLS 160
#define ROWS 80

int main()
{
    Game game(COLS, ROWS, CELL_SIZE);
    game.run();

    return 0;
}