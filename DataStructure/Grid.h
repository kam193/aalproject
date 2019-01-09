#ifndef AAL_GRID_H
#define AAL_GRID_H

#include <vector>

#include "Orientation.h"

using namespace std;

class Grid
{
    int width;
    int height;

    vector<vector<int>> grid;

  public:
    Grid(int width, int height, std::vector<std::vector<int>> grid)
        : width(width), height(height), grid(grid) {}

    // Grid(Grid &old);
    void insert(int x, int y, Orientation orientation);
    bool is_possible_to_insert(int x, int y, Orientation orientation);
    int get_free_count();
    int get_width();
    int get_height();

  private:
    struct Field
    {
        int x;
        int y;
    };

    vector<Field> getFieldsCoordinates(int x, int y, Orientation orientation);
};

#endif