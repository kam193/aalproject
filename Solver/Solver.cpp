#include "Solver.h"

Solver::Solver(Grid grid) : analyzedGrid(grid)
{
    possibleOrientations.reserve(grid.get_height());
    for (int y = 0; y < grid.get_height(); ++y)
        possibleOrientations.push_back(vector<vector<Orientation>>(grid.get_width()));
}

void Solver::generate_possible_orientations()
{
    for (int y = 0; y < analyzedGrid.get_height(); ++y)
        for (int x = 0; x < analyzedGrid.get_width(); ++x)
        {
            if (analyzedGrid.get_field(x, y) == FREE)
            {
                for (Orientation orient : AllOrientations)
                    if (analyzedGrid.is_possible_to_insert(x, y, orient))
                        possibleOrientations[y][x].push_back(orient);
                possibilitiesQueue.push({possibleOrientations[y][x].size(), {x, y}});
            }
        }
}

bool Solver::update_possibile_orientations(Field field)
{
    struct ToUpdate
    {
        Field field;
        vector<Orientation> possible;
    };

    list<ToUpdate> updates;

    for (int x = max(0, field.x - 5); x < min(field.x + 5, analyzedGrid.get_width()); ++x)
        for (int y = max(0, field.y - 5); y < min(field.y + 5, analyzedGrid.get_height()); ++y)
            if ((field.x != x || field.y != y) && analyzedGrid.get_field(x, y) == FREE)
            {
                ToUpdate update;
                update.field = {x, y};
                for (Orientation orient : AllOrientations)
                    if (analyzedGrid.is_possible_to_insert(x, y, orient))
                        update.possible.push_back(orient);
                if (update.possible.size() == 0)
                    return false;
                updates.push_back(update);
            }

    for (ToUpdate &update : updates)
    {
        if (possibleOrientations[update.field.y][update.field.x].size() != update.possible.size())
        {
            possibleOrientations[update.field.y][update.field.x] = update.possible;
            // copy(update.possible.begin(), update.possible.end(), possibleOrientations[update.field.y][update.field.x].begin());
            possibilitiesQueue.push({update.possible.size(), {update.field}});
        }
    }
    return true;
}

int Solver::solve()
{
    generate_possible_orientations();
    // mam: kolejkę priorytetową po najmniejszej liczbie kombinacji
    // stos wstawionych (pole, orientacja, możliwe orientacje)

    int counted = 0;
    // jestem w jakimś stanie
    while (!possibilitiesQueue.empty())
    {
        // wybieram pierwsze z kolejki (sprawdzam, czy jest to wolne)
        QueueEntry top = possibilitiesQueue.top();
        possibilitiesQueue.pop();

        if (analyzedGrid.get_field(top.field) != FREE ||
            possibleOrientations[top.field.y][top.field.x].size() != top.possibilitiesCount)
            continue;

        if (possibleOrientations[top.field.y][top.field.x].size() == 0)
        {
            if (addedStack.empty())
                return counted;
            revoke_last();
            continue;
        }

        addedStack.push({top.field});
        // wrzucam na stos i wstawiam pierwszą możliwość
        analyzedGrid.insert(top.field,
                            possibleOrientations[top.field.y][top.field.x].back());

        // sprawdzam czy wypełnione [tak -> x]
        if (analyzedGrid.get_free_count() == 0)
        {
            counted++;
            int b = 0;
            revoke_last();
            continue;
        }
        // uaktualniam kolejkę [ktoś nie może już -> x]
        if (!update_possibile_orientations(top.field))
        {
            revoke_last();
            continue;
        }
    }
    return counted;
}

// [x]: czyli wycofanie ostatniego
// usuwam wstawienie
// uaktualniam kolejkę
// wrzucam do kolejki ostatni element ze stosu, z możliwościami mniejszymi o poprzednio wstawioną
void Solver::revoke_last()
{
    StackEntry top = addedStack.top();
    addedStack.pop();
    analyzedGrid.remove(top.field, possibleOrientations[top.field.y][top.field.x].back());
    update_possibile_orientations(top.field);
    possibleOrientations[top.field.y][top.field.x].pop_back();
    possibilitiesQueue.push({possibleOrientations[top.field.y][top.field.x].size(), top.field});
}