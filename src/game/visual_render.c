#include "libft.h"
#include "error.h"
#include "solong_bonus.h"
#include <stdlib.h>
#include <unistd.h>

void display_move_count(int move_count)
{
    char *s;

    s = ft_itoa(move_count);
    if (!s)
        return;
    write(1, "MOVE COUNT => ", 14);
    write(1, s, ft_strlen(s));
    write(1, "\n", 1);
    free(s);
}

static int texture_to_window(mlx_t *mlx, mlx_texture_t *texture, struct s_coord element_coord)
{
    mlx_image_t* img = mlx_texture_to_image(mlx, texture);
    if (!img)
        return (error_manager(MLX));
    if (mlx_image_to_window(mlx, img, element_coord.x * 64, element_coord.y * 64) < 0)
        return (error_manager(MLX));
    return (NO_ERRORS);
}

int render_element(struct s_mlx_data mlx_data, char element, size_t x, size_t y)
{
    mlx_texture_t *texture;
    struct s_coord element_coord = {x, y};

    texture = NULL;
    if (element == '1')
        texture = mlx_data.textures.wall;
    else if (element == '0' || element == 'P')
        texture = mlx_data.textures.empty;
    else if (element == 'E')
        texture = mlx_data.textures.exit;
    else if (element == 'C')
    {
        if (render_element(mlx_data, '0', x, y))
            return (1);
        texture = mlx_data.textures.collectible;
    }
    if (texture && texture_to_window(mlx_data.mlx, texture, element_coord))
        return (1);
    return (0);
}

static int render_player(char **map, struct s_mlx_data *mlx_data)
{
    struct s_coord player_coord;

    if (!map || !*map)
        return (error_manager(MEMORY));
    player_coord = get_element_coord(map, 'P', 1);
    mlx_data->player_img = mlx_texture_to_image(mlx_data->mlx, mlx_data->textures.player);
    if (!mlx_data->player_img)
        return (error_manager(MLX));
    if (mlx_image_to_window(mlx_data->mlx, mlx_data->player_img, player_coord.x * 64, player_coord.y * 64 + 20) < 0)
        return (error_manager(MLX));
    return (NO_ERRORS);
}

int visual_render(char **map, t_game_data *game_data)
{
    size_t i;
    size_t j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            render_element(game_data->mlx_data, map[i][j], j, i);
            j++;
        }
        i++;
    }
    if (render_enemy(map, game_data))
        return (1);
    if (render_player(map, &(game_data->mlx_data)))
        return (1);
    return (0);
}