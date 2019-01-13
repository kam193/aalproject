#include <algorithm>

#include "acutest.h"

#include "../DataStructure/Grid.h"

using namespace std;

bool compare_vectors(vector<Field> &vec1, vector<Field> &vec2)
{
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    return vec1 == vec2;
}

void test_generating_coordinates(void)
{
    // Chceck if Grid::fields_coordinate generate correct values
    vector<vector<char>> grid_8x8{{'_', '_', '_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_', '_', '_'}};
    Grid grid(8, 8, grid_8x8);

    struct orient_case
    {
        Orientation orient;
        vector<Field> expected;
    };
    int test_x = 4;
    int test_y = 4;

    vector<orient_case> cases = { //TODO: All cases
        {O1, {{4, 4}, {5, 4}, {6, 4}, {6, 5}}},
        {O2, {{3, 4}, {4, 4}, {5, 4}, {5, 5}}}};

    for (auto &test_case : cases)
    {
        auto results = grid.fields_coordinates(test_x, test_y, test_case.orient);
        TEST_CHECK(compare_vectors(results, test_case.expected) == true);
    }
}

TEST_LIST = {{"coordinates", test_generating_coordinates},
             {0}};