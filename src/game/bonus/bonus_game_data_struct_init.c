/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_game_data_struct_init.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:06:04 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 14:34:45 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"
#include <stddef.h>

static struct s_num_images	num_images_null_init(void)
{
	struct s_num_images	num_images;

	num_images.number_0 = NULL;
	num_images.number_1 = NULL;
	num_images.number_2 = NULL;
	num_images.number_3 = NULL;
	num_images.number_4 = NULL;
	num_images.number_5 = NULL;
	num_images.number_6 = NULL;
	num_images.number_7 = NULL;
	num_images.number_8 = NULL;
	num_images.number_9 = NULL;
	return (num_images);
}

struct s_game_images	game_images_null_init(void)
{
	struct s_game_images	game_images;

	game_images.collectible = NULL;
	game_images.exit = NULL;
	game_images.empty = NULL;
	game_images.wall = NULL;
	game_images.player_img = NULL;
	game_images.enemy_img1 = NULL;
	game_images.enemy_img2 = NULL;
	return (game_images);
}

struct s_mlx_textures	game_textures_null_init(void)
{
	struct s_mlx_textures	game_textures;

	game_textures.player = NULL;
	game_textures.wall = NULL;
	game_textures.empty = NULL;
	game_textures.exit = NULL;
	game_textures.collectible = NULL;
	game_textures.enemy_1 = NULL;
	game_textures.enemy_2 = NULL;
	game_textures.number_0 = NULL;
	game_textures.number_1 = NULL;
	game_textures.number_2 = NULL;
	game_textures.number_3 = NULL;
	game_textures.number_4 = NULL;
	game_textures.number_5 = NULL;
	game_textures.number_6 = NULL;
	game_textures.number_7 = NULL;
	game_textures.number_8 = NULL;
	game_textures.number_9 = NULL;
	return (game_textures);
}

struct s_mlx_data	mlx_data_null_init(void)
{
	struct s_mlx_data	mlx_data;
	size_t				i;

	mlx_data.mlx = NULL;
	mlx_data.textures = game_textures_null_init();
	mlx_data.images = game_images_null_init();
	i = 0;
	while (i < 4)
	{
		mlx_data.counter[i] = num_images_null_init();
		i++;
	}
	return (mlx_data);
}

t_game_data	game_data_null_init(void)
{
	t_game_data	game_data;

	game_data.mlx_data = mlx_data_null_init();
	game_data.game_logic = game_logic_null_init();
	game_data.map = NULL;
	return (game_data);
}
