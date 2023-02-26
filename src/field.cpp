#include "field.hpp"

using namespace rd;

Field::Field(int cols, int rows, int cell_size) : cell_size(cell_size), cols(cols), rows(rows)
{
    current = vector<vector<int>>(cols, vector<int>(rows, 0));
    next = vector<vector<int>>(cols, vector<int>(rows, 0));

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            bool alive = random_bool(0.5);
            if (alive)
                current[i][j] = 1;
        }
    }
}

void Field::draw(Window *window)
{
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (current[i][j])
            {
                int color[3] = {200, 200, 200};
                window->drawRect(i * cell_size, j * cell_size, cell_size, cell_size, color);
            }
        }
    }
}

void Field::update()
{
    next = current;

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            int count = neighbors(i, j);

            if (current[i][j])
            {
                if (count > 3 || count < 2)
                    next[i][j] = 0;
            }

            else if (count == 3)
                next[i][j] = 1;
        }
    }

    current = next;
    next = vector<vector<int>>(cols, vector<int>(rows, 0));
}

int Field::neighbors(int x, int y)
{
    int count = 0;

    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            int col = (x + i + current.size()) % current.size();
            int row = (y + j + current[x].size()) % current[x].size();

            count += current[col][row];
        }
    }

    count -= current[x][y];
    return count;
}