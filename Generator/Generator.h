#ifndef AAL_GENERATOR_H
#define AAL_GENERATOR_H

#include <list>
#include <cstdlib>
#include "../DataStructure/Grid.h"

class Generator : private Grid
{
    Grid grid;
    list<Field> free_fields;
    const int END_RAND = 6;
    
    const int INSERT_2x2_VERTICAL = 1;
    const int INSERT_2x2_HORIZONTAL = 2;
    const int INSERT_4x4 = 3;

  private:
    bool try_insert_2x2_horizonal(Field field);
    bool try_insert_2x2_vertical(Field field);
    bool try_insert_4x4(Field field);
    bool try_insert_L(Field field, Orientation orient);

  public:
    Generator(int height, int width);
    Grid generate();
};

#endif