#include <vector>

#include "Grid.h"

using namespace std;

Grid::Grid(int width, int height, std::vector<std::vector<char>> originalGrid)
    : width(width), height(height), free_count(0), last_index(0)
{
    grid.reserve(height);
    for (auto &line : originalGrid)
    {
        grid.push_back(vector<int>());
        grid.back().reserve(width);
        for (auto value : line)
        {
            if (value == '#')
                grid.back().push_back(BLOCKED);
            else
            {
                grid.back().push_back(FREE);
                ++free_count;
            }
        }
    }
}

Grid::Grid(const Grid &old)
    : width(old.width), height(old.height), free_count(old.free_count),
      last_index(old.last_index), grid(old.grid) {}

bool Grid::is_possible_to_insert(int x, int y, Orientation orientation)
{
    vector<Field> fields = fields_coordinates(x, y, orientation);
    if (fields.size() == 4)
    {
        for (Field field : fields)
            if (grid[field.y][field.x] != FREE)
                return false;
        return true;
    }
    return false;
}

void Grid::insert(Field field, Orientation orientation){
    insert(field.x, field.y, orientation);
}

void Grid::insert(int x, int y, Orientation orientation)
{
    auto fields = fields_coordinates(x, y, orientation);
    ++last_index;
    for (auto field : fields)
        get_field(field) = last_index;
    free_count -= fields.size();
}

void Grid::remove(Field field, Orientation orientation){
    remove(field.x, field.y, orientation);
}

void Grid::remove(int x, int y, Orientation orientation){
    auto fields = fields_coordinates(x, y, orientation);
    for (auto field : fields)
        get_field(field) = FREE;
    free_count += fields.size();
}

vector<Field> Grid::fields_coordinates(int x, int y, Orientation orientation)
{
    vector<Field> moves(4);

    // For each of orientation case, get the position
    // of each field relative to given x, y
    if (orientation == O1)
        moves = {{0, 0}, {1, 0}, {2, 0}, {2, 1}};
    else if (orientation == O2)
        moves = {{-1, 0}, {0, 0}, {1, 0}, {1, 1}};
    else if (orientation == O3)
        moves = {{-2, 0}, {-1, 0}, {0, 0}, {0, 1}};
    else if (orientation == O4)
        moves = {{-2, -1}, {-1, -1}, {0, -1}, {0, 0}};
    else if (orientation == O5)
        moves = {{0, 0}, {1, 0}, {0, 1}, {0, 2}};
    else if (orientation == O6)
        moves = {{-1, 0}, {0, 0}, {-1, 1}, {-1, 2}};
    else if (orientation == O7)
        moves = {{0, -1}, {1, -1}, {0, 0}, {0, 1}};
    else if (orientation == O8)
        moves = {{0, -2}, {1, -2}, {0, -1}, {0, 0}};
    else if (orientation == O9)
        moves = {{0, 0}, {0, 1}, {0, 2}, {-1, 2}};
    else if (orientation == O10)
        moves = {{0, -1}, {0, 0}, {0, 1}, {-1, 1}};
    else if (orientation == O11)
        moves = {{0, -2}, {0, -1}, {0, 0}, {-1, 0}};
    else if (orientation == O12)
        moves = {{1, -2}, {1, -1}, {1, 0}, {0, 0}};
    else if (orientation == O13)
        moves = {{0, 0}, {0, 1}, {1, 1}, {2, 1}};
    else if (orientation == O14)
        moves = {{0, -1}, {0, 0}, {1, 0}, {2, 0}};
    else if (orientation == O15)
        moves = {{-1, -1}, {-1, 0}, {0, 0}, {1, 0}};
    else if (orientation == O16)
        moves = {{-2, -1}, {-2, 0}, {-1, 0}, {0, 0}};
    else if (orientation == O17)
        moves = {{0, 0}, {1, 0}, {2, 0}, {2, -1}};
    else if (orientation == O18)
        moves = {{-1, 0}, {0, 0}, {1, 0}, {1, -1}};
    else if (orientation == O19)
        moves = {{-2, 0}, {-1, 0}, {0, 0}, {0, -1}};
    else if (orientation == O20)
        moves = {{0, 0}, {0, 1}, {-1, 1}, {-2, 1}};
    else if (orientation == O21)
        moves = {{0, 0}, {1, 0}, {1, 1}, {1, 2}};
    else if (orientation == O22)
        moves = {{-1, 0}, {0, 0}, {0, 1}, {0, 2}};
    else if (orientation == O23)
        moves = {{-1, -1}, {0, -1}, {0, 0}, {0, 1}};
    else if (orientation == O24)
        moves = {{-1, -2}, {0, -2}, {0, -1}, {0, 0}};
    else if (orientation == O25)
        moves = {{0, 0}, {0, 1}, {0, 2}, {1, 2}};
    else if (orientation == O26)
        moves = {{0, -1}, {0, 0}, {0, 1}, {1, 1}};
    else if (orientation == O27)
        moves = {{0, -2}, {0, -1}, {0, 0}, {1, 0}};
    else if (orientation == O28)
        moves = {{0, 0}, {-1, 0}, {-1, -1}, {-1, -2}};
    else if (orientation == O29)
        moves = {{0, 0}, {0, -1}, {1, -1}, {2, -1}};
    else if (orientation == O30)
        moves = {{0, 1}, {0, 0}, {1, 0}, {2, 0}};
    else if (orientation == O31)
        moves = {{-1, 1}, {-1, 0}, {0, 0}, {1, 0}};
    else if (orientation == O32)
        moves = {{0, 0}, {-1, 0}, {-2, 0}, {-2, 1}};

    for (Field &move : moves)
    {
        move.x += x;
        move.y += y;

        // It's not possible to insert object in this
        // orientation on those coordinates, return empty
        if (move.x < 0 || move.x >= width)
            return vector<Field>();
        if (move.y < 0 || move.y >= height)
            return vector<Field>();
    }

    return moves;
}

void Grid::clear(){
    for(auto &row : grid)
        for (auto &field : row)
            if (field != BLOCKED)
                field = FREE;
}

istream &operator>>(istream &stream, Grid &grid){
    stream >> grid.height >> grid.width;

    grid.grid.resize(grid.height);
    grid.free_count = 0;

    char tmp;
    for (int y = 0; y < grid.height; ++y){
        grid.grid[y].resize(grid.width);
        for (int x = 0; x < grid.width; ++x)
        {
            stream >> tmp;
            if (tmp == '#')
                grid.grid[y][x] = BLOCKED;
            else
            {
                grid.grid[y][x] = FREE;
                grid.free_count++;
            }
        }
    }

    return stream;
}

std::ostream &operator<<(std::ostream &stream, const Grid &grid)
{
    stream << grid.height << " " << grid.width << endl;

    for (auto &row : grid.grid)
    {
        for (auto element : row)
        {
            if (element == FREE)
                stream << "_";
            else if (element == BLOCKED)
                stream << "#";
            else
                stream << element;
        }
        stream << endl;
    }

    return stream;
}