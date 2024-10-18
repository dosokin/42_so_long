/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:11:18 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 14:33:16 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "solong.h"
#include <stdlib.h>
#include <unistd.h>

static struct s_game_logic	init_game_logic(char **map)
{
	struct s_game_logic	game_logic;

	game_logic = game_logic_null_init();
	if (!map || !*map)
		return (game_logic);
	game_logic.player = get_element_coord(map, 'P', 1);
	game_logic.remaining_collectibles = count_elements(map).collectibles;
	game_logic.keys_status = key_status_null_init();
	game_logic.status = DEFAULT;
	return (game_logic);
}

static int	init_game_textures(struct s_mlx_data *mlx_data)
{
	if (png_to_texture(&mlx_data->textures.exit, get_texture_path(EXIT)))
		return (error_manager(TEXTURES));
	if (png_to_texture(&mlx_data->textures.wall, get_texture_path(WALL)))
		return (error_manager(TEXTURES));
	if (png_to_texture(&mlx_data->textures.empty, get_texture_path(EMPTY)))
		return (error_manager(TEXTURES));
	if (png_to_texture(&mlx_data->textures.collectible,
			get_texture_path(COLLECTIBLE)))
		return (error_manager(TEXTURES));
	if (png_to_texture(&mlx_data->textures.player, get_texture_path(PLAYER)))
		return (error_manager(TEXTURES));
	return (NO_ERRORS);
}

static int	init_game_images(struct s_mlx_data *mlx_data)
{
	struct s_mlx_textures	*textures;
	struct s_game_images	*images;

	textures = &mlx_data->textures;
	images = &mlx_data->images;
	if (texture_to_img(&images->exit, textures->exit, mlx_data->mlx))
		return (error_manager(TEXTURES));
	if (texture_to_img(&images->player_img, textures->player, mlx_data->mlx))
		return (error_manager(TEXTURES));
	if (texture_to_img(&images->collectible, textures->collectible,
			mlx_data->mlx))
		return (error_manager(TEXTURES));
	if (texture_to_img(&images->empty, textures->empty, mlx_data->mlx))
		return (error_manager(TEXTURES));
	if (texture_to_img(&images->wall, textures->wall, mlx_data->mlx))
		return (error_manager(TEXTURES));
	delete_textures(&(mlx_data->textures));
	return (NO_ERRORS);
}

static char	**init_map(int fd)
{
	char	*brut_map;
	char	**map;

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

int	init_game(int fd, t_game_data *game_data)
{
	int	width;
	int	height;

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
	width = 64 * ft_strlen(game_data->map[0]);
	height = 64 * count_array(game_data->map);
	game_data->mlx_data.mlx = mlx_init(width, height, "BEAVERLAND", true);
	if (!game_data->mlx_data.mlx)
		return (1);
	if (init_game_images(&(game_data->mlx_data)))
		return (1);
	if (visual_render(game_data->map, game_data))
		return (1);
	return (0);
}
