#ifndef AAL_SOLVER_H
#define AAL_SOLVER_H

#include <list>
#include <queue>

#include "../DataStructure/Grid.h"

class Solver
{
  Grid analyzedGrid;
  vector<vector<list<Orientation>>> possibleOrientations;

public:
  Solver(Grid grid);
  int solve();

private:
  struct QueueEntry
  {
    int possibilitiesCount;
    Field field;
  };

  // priority_queue<QueueEntry> possibilitiesQueue;
  // TODO: comparator

  void generate_possible_orientations();
};

#endif