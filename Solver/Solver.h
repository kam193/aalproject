#ifndef AAL_SOLVER_H
#define AAL_SOLVER_H

#include <list>
#include <queue>
#include <stack>

#include "../DataStructure/Grid.h"

class Solver
{
  Grid analyzedGrid;
  vector<vector<vector<Orientation>>> possibleOrientations;

public:
  Solver(Grid grid);
  int solve();

private:
  struct QueueEntry
  {
    long unsigned int possibilitiesCount;
    Field field;
    bool operator<(const QueueEntry &other) const {
      return possibilitiesCount > other.possibilitiesCount;
    }
  };

  struct StackEntry
  {
    Field field;
    // list<Orientation> possibleOrientation;
  };

  priority_queue<QueueEntry> possibilitiesQueue;
  // TODO: comparator
  stack<StackEntry> addedStack;

  void generate_possible_orientations();
  bool update_possibile_orientations(Field field);
  void revoke_last();
};

#endif