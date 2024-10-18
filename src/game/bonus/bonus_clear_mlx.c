/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:12:51 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/16 08:12:53 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "solong_bonus.h"

static void	delete_game_images(struct s_game_images *images, mlx_t *mlx)
{
	mlx_image_t	**image;
	size_t		i;

	if (!images)
		return ;
	i = 0;
	while (i < 7)
	{
		image = get_game_image_location(i, images);
		if (*image)
		{
			mlx_delete_image(mlx, *image);
			*image = NULL;
		}
		i++;
	}
}

static void	delete_num_images(struct s_mlx_data mlx_data, mlx_t *mlx)
{
	struct s_num_images	*num_images;
	mlx_image_t			*image;
	size_t				i;
	size_t				j;

	i = 0;
	while (i < 4)
	{
		num_images = &(mlx_data.counter[i]);
		j = 0;
		while (j < 10)
		{
			image = *(get_num_image_location(i, num_images));
			if (image)
			{
				mlx_delete_image(mlx, image);
				image = NULL;
			}
			j++;
		}
		i++;
	}
}

void	delete_textures(struct s_mlx_textures *textures)
{
	size_t			i;
	mlx_texture_t	*texture;

	i = 0;
	while (i < 7)
	{
		texture = *(get_game_texture_location(i, textures));
		if (texture)
			mlx_delete_texture(texture);
		i++;
	}
    i = 0;
	while (i < 10)
	{
		texture = *(get_num_texture_location(i, textures));
		if (texture)
			mlx_delete_texture(texture);
		i++;
	}
}

void	delete_images(struct s_mlx_data mlx_data, mlx_t *mlx)
{
	delete_game_images(&(mlx_data.images), mlx);
	delete_num_images(mlx_data, mlx);
}
