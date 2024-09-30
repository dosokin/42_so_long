#include <stdbool.h>
#include <stdlib.h>
#include "libft.h"
#include "solong_bonus.h"

bool    check_file_extension(char *filename, char *expected_extension)
{
    size_t     len_extension;
    size_t     len_filename;

    if (!filename || !expected_extension)
        return false;
    len_extension = ft_strlen(expected_extension);
    len_filename = ft_strlen(filename);
    if (len_filename < len_extension + 1)
        return false;
    filename += len_filename - (len_extension + 1);
    if (filename[0] != '.')
        return false;
    filename++;
    if (ft_strncmp(expected_extension, filename, len_extension))
        return false;
    return (true);
}

char	*get_content(int fd)
{
    char    *next_line;
    char    *map;
    char    *map_copy;

    map = malloc(sizeof(char));
    if (!map)
        return NULL;
    *map = 0;
    next_line = get_next_line(fd);
    while (next_line)
    {
        map_copy = ft_strdup(map);
        free(map);
        if (!map_copy) {
            free(next_line);
            break;
        }
        map = custom_strcat(map_copy, next_line);
        free(next_line);
        free(map_copy);
        next_line = get_next_line(fd);
    }
    return (map);
}