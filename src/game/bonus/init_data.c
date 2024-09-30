#include "libft.h"
#include "error.h"
#include "solong_bonus.h"
#include <stdlib.h>
#include <unistd.h>


static struct s_game_logic init_game_logic(char **map)
{
    struct s_game_logic game_logic = {0};

    if (!map || !*map)
        return (game_logic);
    game_logic.player = get_element_coord(map, 'P', 1);
    game_logic.remaining_collectibles = count_elements(map).collectibles;
    return (game_logic);
}

static int  init_game_textures(struct s_mlx_data *mlx_data)
{
    size_t i;

    i = 0;
    while (i < 17)
    {
        if (png_to_texture(get_texture_location(i, &(mlx_data->textures)), get_texture_path(i)))
            return (error_manager(TEXTURES));
        i++;
    }
    return (NO_ERRORS);
}

static int  init_game_images(struct s_mlx_data *mlx_data)
{
    size_t i;
    size_t j;
    struct s_num_images *num_images;

    i = 0;
    while (i < 7)
    {
        if (texture_to_img(get_image_location(i, &(mlx_data->images)), *get_texture_location(i, &(mlx_data->textures)), mlx_data->mlx))
            return (error_manager(TEXTURES));
        i++;
    }
    i = 0;
    while (i < 4)
    {
        num_images = &(mlx_data->counter[i]);
        j = 0;
        while (j < 10)
        {
            if (texture_to_img(get_num_location(j, num_images), *get_texture_location(j + 7, &(mlx_data->textures)), mlx_data->mlx))
                return (error_manager(TEXTURES));
            j++;
        }
        i++;
    }
    delete_textures(&(mlx_data->textures));
    return (NO_ERRORS);
}

static char **init_map(int fd)
{
    char    *brut_map;
    char    **map;

    brut_map = get_content(fd);
    close(fd);
    if (!brut_map)
    {
        error_manager(MEMORY);
        return (NULL);
    }
    map = extract_map(brut_map);
    free(brut_map);
    if (!map)
    {
        error_manager(MEMORY);
        return (NULL);
    }
    return (map);
}

int init_game(int fd, t_game_data *game_data)
{
    if (!game_data)
        return (1);
    game_data->map = init_map(fd);
    if (!game_data->map)
        return (1);
    if (check_map_validity(game_data->map))
        return (1);
    game_data->game_logic = init_game_logic(game_data->map);
    if (init_game_textures(&(game_data->mlx_data)))
        return (1);
    game_data->mlx_data.mlx = mlx_init(64 * ft_strlen(game_data->map[0]),64 * count_array(game_data->map), "BEAVERLAND_BONUS", true);
    if (!game_data->mlx_data.mlx)
        return (1);
    if (init_game_images(&(game_data->mlx_data)))
        return (1);
    if (visual_render(game_data->map, game_data))
        return (1);
    return (0);
}