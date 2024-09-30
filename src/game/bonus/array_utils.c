
#include <stdlib.h>
#include "libft.h"

void *free_array(char **s)
{
    int i;

    if (!s || !*s)
        return (NULL);
    i = 0;
    while (s[i])
    {
        free(s[i]);
        i++;
    }
    free(s);
    return (NULL);
}

int count_array(char **s)
{
    int i;

    if (!s || !*s)
        return (-1);
    i = 0;
    while (s[i])
        i++;
    return (i);
}

char **array_dup(char **array)
{
    char **dup;
    size_t i;

    if (!array || !*array)
        return (NULL);
    dup = malloc((count_array(array) + 1) * sizeof(char*));
    if (!dup)
        return (NULL);
    i = 0;
    while (array[i])
    {
        dup[i] = ft_strdup(array[i]);
        if (!dup[i])
        {
            free_array(dup);
            return (NULL);
        }
        i++;
    }
    dup[i] = 0;
    return dup;
}