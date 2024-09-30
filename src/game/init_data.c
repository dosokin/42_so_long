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

static int  init_number_textures(struct s_mlx_textures *textures)
{
    textures->number_0 = mlx_load_png("textures/bonus/numbers/0.png");
    textures->number_1 = mlx_load_png("textures/bonus/numbers/1.png");
    if (!textures->number_0 || !textures->number_1)
        return (error_manager(TEXTURES));
    textures->number_2 = mlx_load_png("textures/bonus/numbers/2.png");
    textures->number_3 = mlx_load_png("textures/bonus/numbers/3.png");
    if (!textures->number_2 || !textures->number_3)
        return (error_manager(TEXTURES));
    textures->number_4 = mlx_load_png("textures/bonus/numbers/4.png");
    textures->number_5 = mlx_load_png("textures/bonus/numbers/5.png");
    if (!textures->number_4 || !textures->number_5)
        return (error_manager(TEXTURES));
    textures->number_6 = mlx_load_png("textures/bonus/numbers/6.png");
    textures->number_7 = mlx_load_png("textures/bonus/numbers/7.png");
    if (!textures->number_6 || !textures->number_7)
        return (error_manager(TEXTURES));
    textures->number_8 = mlx_load_png("textures/bonus/numbers/8.png");
    textures->number_9 = mlx_load_png("textures/bonus/numbers/9.png");
    if (!textures->number_8 || !textures->number_9)
        return (error_manager(TEXTURES));
    return (NO_ERRORS);
}

static int  init_mlx_data(struct s_mlx_data *mlx_data, char **map)
{
    mlx_data->textures.exit = mlx_load_png("textures/manda/exit.png");
    if (!mlx_data->textures.exit)
        return (error_manager(TEXTURES));
    mlx_data->textures.wall = mlx_load_png("textures/manda/wall.png");
    if (!mlx_data->textures.wall)
        return (error_manager(TEXTURES));
    mlx_data->textures.player = mlx_load_png("textures/manda/player.png");
    if (!mlx_data->textures.player)
        return (error_manager(TEXTURES));
    mlx_data->textures.empty = mlx_load_png("textures/manda/empty.png");
    if (!mlx_data->textures.empty)
        return (error_manager(TEXTURES));
    mlx_data->textures.collectible = mlx_load_png("textures/manda/collectible.png");
    if (!mlx_data->textures.collectible)
        return (error_manager(TEXTURES));
    mlx_data->textures.enemy_jump = mlx_load_png("textures/bonus/jump.png");
    if (!mlx_data->textures.enemy_jump)
        return (error_manager(TEXTURES));
    mlx_data->textures.enemy_landing = mlx_load_png("textures/bonus/landing.png");
    if (!mlx_data->textures.enemy_landing)
        return (error_manager(TEXTURES));
    mlx_data->mlx = mlx_init(64 * ft_strlen(map[0]),64 * count_array(map), "BEAVERLAND_BONUS", true);
    if (!mlx_data->mlx)
        return (error_manager(MLX));
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
    if (init_mlx_data(&(game_data->mlx_data), game_data->map))
        return (1);
    if (init_number_textures(&(game_data->mlx_data.textures)))
        return (1);
    if (visual_render(game_data->map, game_data))
        return (1);
    return (0);
}