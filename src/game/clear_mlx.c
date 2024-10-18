/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:11:38 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/16 15:10:30 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "solong.h"

void	delete_game_images(struct s_game_images *images, mlx_t *mlx)
{
	if (!images)
		return ;
	if (images->exit)
		mlx_delete_image(mlx, images->exit);
	if (images->wall)
		mlx_delete_image(mlx, images->wall);
	if (images->empty)
		mlx_delete_image(mlx, images->empty);
	if (images->player_img)
		mlx_delete_image(mlx, images->player_img);
	if (images->collectible)
		mlx_delete_image(mlx, images->collectible);
	*images = game_images_null_init();
}

void	delete_textures(struct s_mlx_textures *textures)
{
	if (textures->exit)
		mlx_delete_texture(textures->exit);
	if (textures->wall)
		mlx_delete_texture(textures->wall);
	if (textures->empty)
		mlx_delete_texture(textures->empty);
	if (textures->player)
		mlx_delete_texture(textures->player);
	if (textures->collectible)
		mlx_delete_texture(textures->collectible);
	*textures = game_textures_null_init();
}
