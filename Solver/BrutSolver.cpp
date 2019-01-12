#include "BrutSolver.h"

BrutSolver::BrutSolver(Grid grid) : analyzedGrid(grid) {}

int BrutSolver::solve()
{
    return check_grid(0, 0, analyzedGrid);
}

int BrutSolver::check_grid(int start_x, int start_y, Grid &grid)
{
    if (grid.get_free_count() == 0)
        return 1;

    while (grid.get_field(start_x, start_y) != FREE)
    {
        ++start_x;
        if (start_x >= grid.get_width())
        {
            ++start_y;
            start_x = 0;
            if (start_y >= grid.get_height())
                return 0;
        }
    }

    int count_solutions = 0;
    for (Orientation orient : AllOrientations)
    {
        if (grid.is_possible_to_insert(start_x, start_y, orient))
        {
            grid.insert(start_x, start_y, orient);
            count_solutions += check_grid(start_x, start_y, grid);
            grid.remove(start_x, start_y, orient);
        }
    }

    return count_solutions;
}