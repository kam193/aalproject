#include <iostream>
#include <vector>

#include "DataStructure/Grid.h"
#include "Solver/Solver.h"
#include "Solver/BrutSolver.h"

using namespace std;

int main(){
    vector<vector<char>> grid_definition {{'_', '_', '_'}, {'_', '#', '_'}, {'_', '_', '_'}};
    vector<vector<char>> grid_definition4 {{'_', '_', '_', '_'}, {'_', '_', '_', '_'}, {'_', '_', '_', '_'}, {'_', '_', '_', '_'}};
    vector<vector<char>> grid_definition8 {{'_', '_', '_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_', '_', '_'}};
    Grid grid;

    cin >> grid;

    BrutSolver solver(grid);
    cout << solver.solve() << endl;

    return 0;
}