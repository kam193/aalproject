#include <iostream>
#include <vector>

#include "DataStructure/Grid.h"
#include "Solver/Solver.h"
#include "Solver/BrutSolver.h"
#include "Generator/Generator.h"
#include "Tester/Tester.h"

using namespace std;

int main(){
    vector<vector<char>> grid_definition {{'_', '_', '_'}, {'_', '#', '_'}, {'_', '_', '_'}};
    vector<vector<char>> grid_definition4 {{'_', '_', '_', '_'}, {'_', '_', '_', '_'}, {'_', '_', '_', '_'}, {'_', '_', '_', '_'}};
    vector<vector<char>> grid_definition8 {{'_', '_', '_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_', '_', '_'}};
    Grid grid;

    // cin >> grid;

    // BrutSolver solver(grid);
    // Solver solver(grid);
    // cout << solver.solve() << endl;
    // Generator gen(10, 10);

    // cout << gen.generate();
    Tester tester;

    tester.run_tests(5, 1, 3, 10);

    return 0;
}