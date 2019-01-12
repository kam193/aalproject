#include <iostream>
#include <vector>

#include "DataStructure/Grid.h"
#include "Solver/Solver.h"

using namespace std;

int main(){
    vector<vector<char>> grid_definition {{'_', '_', '_'}, {'_', '#', '_'}, {'_', '_', '_'}};
    Grid grid(3, 3, grid_definition);

    Solver solver(grid);

    cout << solver.solve() << endl;

    return 0;
}