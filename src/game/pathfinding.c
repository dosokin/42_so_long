#include "stdbool.h"
#include "error.h"
#include "solong.h"

static bool is_one_of(char c, const char *to_find)
{
    size_t i;

    if (!to_find)
        return (false);
    i = 0;
    while (to_find[i])
    {
        if (to_find[i] == c)
            return (true);
        i++;
    }
    return (false);
}

static bool expand_to_adjacents(char ***map, size_t i, size_t j)
{
    const char *expandable = "0EC";
    bool    expanded;

    expanded = false;
    if (is_one_of((*map)[i][j + 1], expandable))
    {
        (*map)[i][j + 1] = 'o';
        expanded = true;
    }
    if (j && is_one_of((*map)[i][j - 1], expandable))
    {
        (*map)[i][j - 1] = 'o';
        expanded = true;
    }
    if (is_one_of((*map)[i + 1][j], expandable))
    {
        (*map)[i + 1][j] = 'o';
        expanded = true;
    }
    if (i && is_one_of((*map)[i - 1][j], expandable))
    {
        (*map)[i - 1][j] = 'o';
        expanded = true;
    }
    return expanded;
}

static bool expand_path(char ***map)
{
    size_t i;
    size_t j;
    bool expanded;

    if (!map || !*map || !**map)
    {
        error_manager(MEMORY);
        return (false);
    }
    expanded = false;
    i = 0;
    while ((*map)[i])
    {
        j = 0;
        while ((*map)[i][j])
        {
            if ((*map)[i][j] == 'o')
                if (expand_to_adjacents(map, i, j))
                    expanded = true;
            j++;
        }
        i++;
    }
    return (expanded);
}

static bool is_path_valid(char **map)
{
    int i;
    int j;

    if (!map || !*map)
    {
        error_manager(MEMORY);
        return (false);
    }
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (is_one_of(map[i][j], "EC"))
                return (false);
            j++;
        }
        i++;
    }
    return (true);
}

int check_path(char **map)
{
    struct s_coord player_coord;
    char **map_copy;
    bool invalid_path;

    invalid_path = false;
    map_copy = array_dup(map);
    if (!map_copy)
        return (error_manager(MEMORY));
    player_coord = get_element_coord(map_copy, 'P', 1);
    map_copy[player_coord.y][player_coord.x] = 'o';
    while (1)
        if (!expand_path(&map_copy))
            break;
    if (!is_path_valid(map_copy))
        invalid_path = true;
    free_array(map_copy);
    return (invalid_path);
}