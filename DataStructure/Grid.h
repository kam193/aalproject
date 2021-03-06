#ifndef AAL_GRID_H
#define AAL_GRID_H

#include <vector>
#include <iostream>

#include "Orientation.h"

using namespace std;

const int BLOCKED = -1;
const int FREE = -2;

struct Field
{
  int x;
  int y;
  
  bool operator== (const Field &other) const
  {
    return (x == other.x && y == other.y);
  }
  bool operator< (const Field &other) const
  {
    if (x != other.x)
      return x < other.x;
    return y < other.y;
  }
};

class Grid
{
  int width;
  int height;
  int free_count;
  int last_index;

  vector<vector<int>> grid;
  vector<Field> fields_coordinates(int x, int y, Orientation orientation);

public:
  Grid() {}
  Grid(int width, int height, std::vector<std::vector<char>> originalGrid);
  Grid(const Grid &old);

  void insert(int x, int y, Orientation orientation);
  void remove(int x, int y, Orientation orientation);
  void insert(Field field, Orientation orientation);
  void remove(Field field, Orientation orientation);
  bool is_possible_to_insert(int x, int y, Orientation orientation);
  int get_free_count() { return free_count; }
  int get_width() { return width; }
  int get_height() { return height; }
  int &get_field(int x, int y) { return grid[y][x]; }
  int &get_field(Field field) { return grid[field.y][field.x]; }
  void clear();

  friend std::istream &operator>>(std::istream &stream, Grid &grid);
  friend std::ostream &operator<<(std::ostream &stream, const Grid &grid);
  
  friend void test_generating_coordinates(void);
  friend class Generator;
};

#endif