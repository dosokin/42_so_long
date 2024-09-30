/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 01:47:35 by dosokin           #+#    #+#             */
/*   Updated: 2024/09/30 01:55:04 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "solong_bonus.h"

static int	ft_rand(void)
{
	static uint64_t	next = 1;

	next = next * 1103515243 + 12345;
	return ((unsigned int)(next / 65536) % 4);
}

static struct s_coord	get_enemy_coord(char **map)
{
	size_t			empties_count;
	struct s_coord	enemy_coord = {0};

	empties_count = count_elements(map).empties;
	if (!empties_count)
		return (enemy_coord);
	enemy_coord = get_element_coord(map, '0', empties_count / 2);
	return (enemy_coord);
}

int	render_enemy(char **map, t_game_data *game_data)
{
	struct s_coord		enemy_coord;
	struct s_mlx_data	*mlx_data;

    if (!map || !*map || !game_data)
        return (error_manager(MEMORY));
    mlx_data = &(game_data->mlx_data);
	enemy_coord = get_enemy_coord(map);
	mlx_data->images.enemy_img2->enabled = false;
	if (mlx_image_to_window(mlx_data->mlx, mlx_data->images.enemy_img1, enemy_coord.x
			* 64 + 20, enemy_coord.y * 64 + 20) < 0)
		return (error_manager(MLX));
	if (mlx_image_to_window(mlx_data->mlx, mlx_data->images.enemy_img2, enemy_coord.x
			* 64 + 20, enemy_coord.y * 64 + 20) < 0)
		return (error_manager(MLX));
	game_data->game_logic.enemy = enemy_coord;
	return (NO_ERRORS);
}


static void	enemy_movement(t_game_data *game_data, struct s_coord *coord,
		int type)
{
	char	target_element;

	if (type == 0)
		target_element = game_data->map[coord->y][coord->x + 1];
	else if (type == 1)
		target_element = game_data->map[coord->y][coord->x - 1];
	else if (type == 2)
		target_element = game_data->map[coord->y + 1][coord->x];
	else
		target_element = game_data->map[coord->y - 1][coord->x];
	if (target_element == '1' || target_element == 'C' || target_element == 'E')
		return ;
	if (type == 0)
		coord->x += 1;
	else if (type == 1)
		coord->x -= 1;
	else if (type == 2)
		coord->y += 1;
	else if (type == 3)
		coord->y -= 1;
	game_data->mlx_data.images.enemy_img1->instances->x = coord->x * 64 + 20;
	game_data->mlx_data.images.enemy_img1->instances->y = coord->y * 64 + 20;
	game_data->mlx_data.images.enemy_img2->instances->x = coord->x * 64 + 20;
	game_data->mlx_data.images.enemy_img2->instances->y = coord->y * 64 + 20;
}

void	enemy_animation(void *p)
{
	t_game_data			*game_data;
	struct s_game_images	*images;
	static int			sprite = 0;
	static int			move = 0;

	game_data = p;
	sprite++;
	move++;
	if (sprite > 10)
	{
		images = &(game_data->mlx_data.images);
		sprite = 0;
		images->enemy_img1->enabled = !images->enemy_img1->enabled;
		images->enemy_img2->enabled = !images->enemy_img2->enabled;
	}
	if (move > 50)
	{
		move = 0;
		enemy_movement(game_data, &(game_data->game_logic.enemy), ft_rand());
	}
}
