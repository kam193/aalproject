#include "Solver.h"

Solver::Solver(Grid grid) : analyzedGrid(grid)
{
    possibleOrientations.reserve(grid.get_height());
    for (int y = 0; y < grid.get_height(); ++y)
        possibleOrientations.push_back(vector<list<Orientation>>(grid.get_width()));
}

void Solver::generate_possible_orientations()
{
    for (int y = 0; y < analyzedGrid.get_height(); ++y)
        for (int x = 0; x < analyzedGrid.get_width(); ++x)
        {
            for (Orientation orient : AllOrientations)
                if (analyzedGrid.is_possible_to_insert(x, y, orient))
                    possibleOrientations[y][x].push_back(orient);
            // TODO: insert to queue
        }
}

int Solver::solve()
{
    // TODO: solve
    return 0;
}