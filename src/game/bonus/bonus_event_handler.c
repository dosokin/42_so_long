/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:13:26 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/16 08:13:30 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "solong_bonus.h"

static void	collect_collectibles(t_game_data *game_data, struct s_coord coord)
{
	static bool	first = true;

	game_data->map[coord.y][coord.x] = '0';
	render_element(game_data->mlx_data, '0', coord.x, coord.y);
	if (first)
	{
		game_data->mlx_data.images.player_img->instances->z += 2;
		first = false;
	}
	else
		game_data->mlx_data.images.player_img->instances->z++;
	game_data->game_logic.remaining_collectibles--;
}

static void	vertical_move(t_game_data *game_data, int radix,
		enum e_key_status *key, int *move_count)
{
	struct s_coord	*coord;
	char			target_element;

	coord = &(game_data->game_logic.player);
	target_element = game_data->map[coord->y + radix][coord->x];
	if (target_element == '1' || *key == PRESSED)
		return ;
	(*move_count)++;
	*key = PRESSED;
	coord->y += radix;
	game_data->mlx_data.images.player_img->instances->y += (64 * radix);
	display_move_count(*move_count);
	update_counter(game_data, *move_count);
	if (target_element == 'C')
		collect_collectibles(game_data, *coord);
	else if (target_element == 'E')
		check_win_case(game_data);
}

static void	horizontal_move(t_game_data *game_data, int radix,
		enum e_key_status *key, int *move_count)
{
	struct s_coord	*coord;
	char			target_element;

	coord = &(game_data->game_logic.player);
	target_element = game_data->map[coord->y][coord->x + radix];
	if (target_element == '1' || *key == PRESSED)
		return ;
	(*move_count)++;
	*key = PRESSED;
	coord->x += radix;
	game_data->mlx_data.images.player_img->instances->x += (64 * radix);
	display_move_count(*move_count);
	update_counter(game_data, *move_count);
	if (target_element == 'C')
		collect_collectibles(game_data, *coord);
	else if (target_element == 'E')
		check_win_case(game_data);
}

void	key_press(void *p)
{
	t_game_data				*game_data;
	struct s_keys_status	*keys;
	mlx_t					*mlx;
	static int				move_count = 0;

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
		return ;
}

void	key_release(void *p)
{
	t_game_data				*game_data;
	struct s_keys_status	*keys;
	mlx_t					*mlx;

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
