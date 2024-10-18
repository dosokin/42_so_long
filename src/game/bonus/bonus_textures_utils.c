/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:14:08 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/16 11:56:17 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "solong_bonus.h"

const char	*get_texture_path(size_t index)
{
	const char	*paths[17] = {
		"textures/manda/exit.png",
		"textures/manda/wall.png",
		"textures/manda/empty.png",
		"textures/manda/collectible.png",
		"textures/manda/player.png",
		"textures/bonus/enemy_1.png",
		"textures/bonus/enemy_2.png",
		"textures/bonus/numbers/0.png",
		"textures/bonus/numbers/1.png",
		"textures/bonus/numbers/2.png",
		"textures/bonus/numbers/3.png",
		"textures/bonus/numbers/4.png",
		"textures/bonus/numbers/5.png",
		"textures/bonus/numbers/6.png",
		"textures/bonus/numbers/7.png",
		"textures/bonus/numbers/8.png",
		"textures/bonus/numbers/9.png",
	};

	if (index > 16)
		return (NULL);
	return (paths[index]);
}

mlx_texture_t	**get_game_texture_location(size_t index,
		struct s_mlx_textures *textures)
{
    if (index == 0)
        return (&(textures->exit));
    if (index == 1)
        return (&(textures->wall));
    if (index == 2)
        return (&(textures->empty));
    if (index == 3)
        return (&(textures->collectible));
    if (index == 4)
        return (&(textures->player));
    if (index == 5)
        return (&(textures->enemy_1));
    if (index == 6)
        return (&(textures->enemy_2));
    else
        return (NULL);
}

mlx_texture_t	**get_num_texture_location(size_t index,
		struct s_mlx_textures *textures)
{
    if (index == 0)
        return (&(textures->number_0));
    if (index == 1)
        return (&(textures->number_1));
    if (index == 2)
        return (&(textures->number_2));
    if (index == 3)
        return (&(textures->number_3));
    if (index == 4)
        return (&(textures->number_4));
    if (index == 5)
        return (&(textures->number_5));
    if (index == 6)
        return (&(textures->number_6));
    if (index == 7)
        return (&(textures->number_7));
    if (index == 8)
        return (&(textures->number_8));
    if (index == 9)
        return (&(textures->number_9));
    else
        return (NULL);
}

int	png_to_texture(mlx_texture_t **buffer, const char *path_to_png)
{
	if (!buffer || !path_to_png)
		return (1);
	*buffer = mlx_load_png(path_to_png);
	if (!*buffer)
		return (1);
	return (0);
}

int	texture_to_img(mlx_image_t **buffer, mlx_texture_t *texture, mlx_t *mlx)
{
	if (!buffer || !texture)
		return (1);
	*buffer = mlx_texture_to_image(mlx, texture);
	if (!*buffer)
		return (1);
	return (0);
}
