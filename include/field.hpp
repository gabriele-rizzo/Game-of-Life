#pragma once

#include <vector>
#include "window.hpp"
#include "random.hpp"

using namespace std;

class Field
{
private:
    int cols, rows, cell_size;
    vector<vector<int>> current, next;

    int neighbors(int x, int y);

public:
    Field(int cols, int rows, int cell_size);

    void draw(Window *window);
    void update();
};