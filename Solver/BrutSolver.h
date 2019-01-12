#ifndef AAL_BRUTSOLVER_H
#define AAL_BRUTSOLVER_H

#include "../DataStructure/Grid.h"

class BrutSolver
{
    Grid analyzedGrid;

  public:
    BrutSolver(Grid grid);
    int solve();

  private:
    int check_grid(int start_x, int start_y, Grid &grid);
};

#endif