#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "error.h"
#include "solong.h"

char **extract_map(char *brut_map)
{
    char *truncated;
    char **splitted;
    size_t i;

    if (!brut_map)
        return (NULL);
    while (*brut_map == '\n')
        brut_map++;
    i = 0;
    while (brut_map[i] && !(brut_map[i] == '\n' && brut_map[i + 1] == '\n'))
        i++;
    truncated = ft_strndup(brut_map, i);
    if (!truncated)
        return (NULL);
    splitted = ft_split(truncated, '\n');
    free(truncated);
    if (!splitted)
        return (NULL);
    while (brut_map[i])
    {
        if (brut_map[i] != '\n')
            error_manager(INVALID_MAP);
        free(splitted);
        splitted = NULL;
    }
    return (splitted);
}

struct s_elements_count	count_elements(char **map)
{
    size_t i;
    size_t j;
    struct s_elements_count elements = {0};

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j]) {
            if (map[i][j] == 'C')
                elements.collectibles++;
            else if (map[i][j] == 'P')
                elements.players++;
            else if (map[i][j] == 'E')
                elements.exits++;
            else if (map[i][j] != '1' && map[i][j] != '0')
                elements.others++;
            j++;
        }
        i++;
    }
    return (elements);
}

struct s_coord get_element_coord(char **map, char element, size_t index)
{
    size_t i;
    size_t j;
    size_t c;
    struct s_coord element_coord = {0};

    i = 0;
    c = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == element)
                c++;
            if (c == index)
            {
                element_coord.x = j;
                element_coord.y = i;
                return (element_coord);
            }
            j++;
        }
        i++;
    }
    return (element_coord);
}

