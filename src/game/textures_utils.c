/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:11:25 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/16 11:16:22 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "solong.h"

const char	*get_texture_path(size_t index)
{
	const char	*paths[5] = {
		"textures/manda/exit.png",
		"textures/manda/wall.png",
		"textures/manda/empty.png",
		"textures/manda/collectible.png",
		"textures/manda/player.png",
	};

	if (index > 4)
		return (NULL);
	return (paths[index]);
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
