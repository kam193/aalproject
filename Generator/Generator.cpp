#include <algorithm>

#include "Generator.h"

// private:
//     bool try_insert_2x2_horizonal(Field field);
//     bool try_insert_4x4(Field field);

using namespace std;

bool Generator::try_insert_2x2_vertical(Field field)
{
    if (!(grid.is_possible_to_insert(field.x, field.y, O13) &&
          grid.is_possible_to_insert(field.x + 1, field.y, O1)))
        return false;
    grid.insert(field.x, field.y, O13);
    grid.insert(field.x + 1, field.y, O1);
    return true;
}

bool Generator::try_insert_L(Field field, Orientation orient)
{
    if (!grid.is_possible_to_insert(field.x, field.y, orient))
        return false;
    grid.insert(field, orient);
    return true;
}

Generator::Generator(int height, int width)
{
    grid.width = width;
    grid.height = height;
    grid.free_count = width * height;
    grid.grid.resize(height);
    for (int y = 0; y < height; ++y)
        for (int x = 0; x < width; ++x)
        {
            grid.grid[y].push_back(FREE);
            free_fields.push_back({x, y});
        }
    srand(time(NULL));
}

Grid Generator::generate()
{
    Orientation localOrient[(sizeof(AllOrientations)/sizeof(*AllOrientations))];
    copy(begin(AllOrientations), end(AllOrientations), begin(localOrient));
    int tries = grid.height * grid.width;

    while (tries > 0 && !free_fields.empty())
    {
        int object = rand() % END_RAND;
        random_shuffle(begin(localOrient), end(localOrient));

        auto it = free_fields.begin();
        while (it != free_fields.end())
        {
            if (grid.get_field(*it) != FREE)
            {
                free_fields.erase(it++);
                continue;
            }
            if (object == INSERT_2x2_VERTICAL)
            {
                if (try_insert_2x2_vertical(*it))
                {
                    free_fields.erase(it);
                    break;
                }
            }
            else
            {
                if (try_insert_L(*it, localOrient[0]))
                {
                    free_fields.erase(it);
                    break;
                }
            }
            it++;
        }
        tries--;
    }

    while (!free_fields.empty())
    {
        grid.get_field(free_fields.front()) = BLOCKED;
        free_fields.pop_front();
    }
    grid.clear();

    return grid;
}