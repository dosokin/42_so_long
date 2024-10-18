/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:06:04 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/16 15:06:06 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

struct s_game_images	game_images_null_init(void)
{
    struct s_game_images	game_images;

    game_images.collectible = NULL;
    game_images.exit = NULL;
    game_images.empty = NULL;
    game_images.wall = NULL;
    game_images.player_img = NULL;
    return (game_images);
}

struct s_mlx_data	mlx_data_null_init(void)
{
	struct s_mlx_data	mlx_data;

	mlx_data.mlx = NULL;
	mlx_data.textures = game_textures_null_init();
	mlx_data.images = game_images_null_init();
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

struct s_mlx_textures	game_textures_null_init(void)
{
    struct s_mlx_textures	game_textures;

    game_textures.player = NULL;
    game_textures.wall = NULL;
    game_textures.empty = NULL;
    game_textures.exit = NULL;
    game_textures.collectible = NULL;
    return (game_textures);
}

