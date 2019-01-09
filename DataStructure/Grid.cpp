#include <vector>

#include "Grid.h"

using namespace std;

// void insert(int x, int y, Orientation orientation);

bool Grid::is_possible_to_insert(int x, int y, Orientation orientation){
    vector<Field> fields = getFieldsCoordinates(x, y, orientation);
    if (fields.size() == 4)
        return true;
    return false;
}

vector<Grid::Field> Grid::getFieldsCoordinates(int x, int y, Orientation orientation){
    vector<Field> moves(4);
    
    // For each of orientation case, get the position 
    // of each field relative to given x, y
    if (orientation == O1)
        moves = {{0, 0}, {1, 0}, {2, 0}, {2, 1}};
    else if (orientation == O2)
        moves = {{1, 0}, {0, 0}, {1, 0}, {1, 1}};
    else if (orientation == O3)
        moves = {{-2, 0}, {-1, 0}, {0, 0}, {1, 0}};
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
        moves = {{0, 0}, {0, 1}, {1, 1}, {1, 2}};
    else if (orientation == O14)
        moves = {{0, -1}, {0, 0}, {1, 0}, {2, 0}};
    else if (orientation == O15)
        moves = {{-1, -1}, {-1, 0}, {0, 0}, {1, 0}};
    else if (orientation == O16)
        moves = {{-2, -1}, {-2, 0}, {-1, 0}, {0, 0}};

    for (Field &move : moves){
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