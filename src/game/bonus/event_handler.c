#include "libft.h"
#include "error.h"
#include "solong.h"

static void check_for_special_event(t_game_data *game_data, char target_element, struct s_coord coord)
{
    static bool first = true;
    if (target_element == 'C')
    {
        game_data->map[coord.y][coord.x] = '0';
        render_element(game_data->mlx_data, '0', coord.x, coord.y);
        if (first)
        {
            game_data->mlx_data.player_img->instances->z += 2;
            first = false;
        }
        else
            game_data->mlx_data.player_img->instances->z++;
        game_data->game_logic.remaining_collectibles--;
    }
    else if (target_element == 'E' && !game_data->game_logic.remaining_collectibles)
    {
        game_data->game_logic.success = true;
        mlx_close_window(game_data->mlx_data.mlx);
    }
}

static void vertical_move(t_game_data *game_data, int radix, enum e_key_status *key, int *move_count)
{
    struct s_coord *coord;
    char target_element;

    coord = &(game_data->game_logic.player);
    target_element = game_data->map[coord->y + radix][coord->x];
    if (target_element == '1' || *key == PRESSED)
        return;
    (*move_count)++;
    *key = PRESSED;
    coord->y += radix;
    game_data->mlx_data.player_img->instances->y += (64 * radix);
    display_move_count(*move_count);
    check_for_special_event(game_data, target_element, *coord);
}

static void horizontal_move(t_game_data *game_data, int radix, enum e_key_status *key, int *move_count)
{
    struct s_coord *coord;
    char target_element;

    coord = &(game_data->game_logic.player);
    target_element = game_data->map[coord->y][coord->x + radix];
    if (target_element == '1' || *key == PRESSED)
        return;
    (*move_count)++;
    *key = PRESSED;
    coord->x += radix;
    game_data->mlx_data.player_img->instances->x += (64 * radix);
    display_move_count(*move_count);
    check_for_special_event(game_data, target_element, *coord);
}

void	key_press(void *p)
{
    t_game_data		*game_data;
    struct s_keys_status    *keys;
    mlx_t            *mlx;
    static int	move_count = 0;

    game_data = p;
    mlx = game_data->mlx_data.mlx;
    keys = &(game_data->game_logic.keys_status);
    if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
        mlx_close_window(mlx);
    else if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
        vertical_move(game_data, 1, &(keys->down), &move_count);
    else if (mlx_is_key_down(mlx, MLX_KEY_UP))
        vertical_move(game_data, -1, &(keys->up), &move_count);
    else if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
        horizontal_move(game_data, -1, &(keys->left), &move_count);
    else if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
        horizontal_move(game_data, 1, &(keys->right), &move_count);
    else
        return;
}

void	key_release(void *p)
{
    t_game_data		*game_data;
    struct s_keys_status    *keys;
    mlx_t                   *mlx;

    game_data = p;
    keys = &(game_data->game_logic.keys_status);
    mlx = game_data->mlx_data.mlx;
    if (keys->down == PRESSED && mlx_is_key_up(mlx, MLX_KEY_DOWN))
        keys->down = RELEASED;
    else if (keys->up == PRESSED && mlx_is_key_up(mlx, MLX_KEY_UP))
        keys->up = RELEASED;
    else if (keys->left == PRESSED && mlx_is_key_up(mlx, MLX_KEY_LEFT))
        keys->left = RELEASED;
    else if (keys->right == PRESSED && mlx_is_key_up(mlx, MLX_KEY_RIGHT))
        keys->right = RELEASED;
}