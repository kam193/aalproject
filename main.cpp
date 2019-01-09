#include <iostream>
#include <vector>

#include "DataStructure/Grid.h"
#include "Solver/Solver.h"

using namespace std;

int main(){
    vector<vector<int>> grid_definition {{'_', '_', '_'}, {'_', '#', '_'}, {'_', '_', '_'}};
    Grid grid(3, 3, grid_definition);

    return 0;
}