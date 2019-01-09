#ifndef AAL_SOLVER_H
#define AAL_SOLVER_H

#include "../DataStructure/Grid.h"

class Solver
{
  public:
    virtual ~Solver(){};
    virtual int solve(Grid grid) = 0;
};

#endif