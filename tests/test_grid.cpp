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
        const char *message;
    };
    int test_x = 4;
    int test_y = 4;

    vector<orient_case> cases = {
        {O1, {{4, 4}, {5, 4}, {6, 4}, {6, 5}}, "O1"},
        {O2, {{3, 4}, {4, 4}, {5, 4}, {5, 5}}, "O2"},
        {O3, {{2, 4}, {3, 4}, {4, 4}, {4, 5}}, "O3"},
        {O4, {{2, 3}, {3, 3}, {4, 3}, {4, 4}}, "O4"},
        {O5, {{4, 4}, {5, 4}, {4, 5}, {4, 6}}, "O5"},
        {O6, {{4, 4}, {3, 4}, {3, 5}, {3, 6}}, "O6"},
        {O7, {{4, 4}, {4, 3}, {5, 3}, {4, 5}}, "O7"},
        {O8, {{4, 4}, {4, 3}, {4, 2}, {5, 2}}, "O8"},
        {O9, {{4, 4}, {4, 5}, {4, 6}, {3, 6}}, "O9"},
        {O10, {{4, 4}, {4, 3}, {4, 5}, {3, 5}}, "O10"},
        {O11, {{4, 4}, {4, 3}, {4, 2}, {3, 4}}, "O11"},
        {O12, {{4, 4}, {5, 4}, {5, 3}, {5, 2}}, "O12"},
        {O13, {{4, 4}, {4, 5}, {5, 5}, {6, 5}}, "O13"},
        {O14, {{4, 4}, {4, 3}, {5, 4}, {6, 4}}, "O14"},
        {O15, {{4, 4}, {3, 4}, {3, 3}, {5, 4}}, "O15"},
        {O16, {{4, 4}, {3, 4}, {2, 4}, {2, 3}}, "O16"}};

    for (auto &test_case : cases)
    {
        auto results = grid.fields_coordinates(test_x, test_y, test_case.orient);
        TEST_CHECK_(compare_vectors(results, test_case.expected) == true, test_case.message);
    }
}

TEST_LIST = {{"coordinates", test_generating_coordinates},
             {0}};