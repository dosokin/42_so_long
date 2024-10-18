/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_img_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:56:37 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 14:34:29 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "solong_bonus.h"

mlx_image_t	**get_num_image_location(size_t index, struct s_num_images *images)
{
	if (index == 0)
		return (&(images->number_0));
	if (index == 1)
		return (&(images->number_1));
	if (index == 2)
		return (&(images->number_2));
	if (index == 3)
		return (&(images->number_3));
	if (index == 4)
		return (&(images->number_4));
	if (index == 5)
		return (&(images->number_5));
	if (index == 6)
		return (&(images->number_6));
	if (index == 7)
		return (&(images->number_7));
	if (index == 8)
		return (&(images->number_8));
	if (index == 9)
		return (&(images->number_9));
	else
		return (NULL);
}

mlx_image_t	**get_game_image_location(size_t index,
		struct s_game_images *images)
{
	if (index == 0)
		return (&(images->exit));
	else if (index == 1)
		return (&(images->wall));
	else if (index == 2)
		return (&(images->empty));
	else if (index == 3)
		return (&(images->collectible));
	else if (index == 4)
		return (&(images->player_img));
	else if (index == 5)
		return (&(images->enemy_img1));
	else if (index == 6)
		return (&(images->enemy_img2));
	else
		return (NULL);
}

int	load_num_images(struct s_num_images *counter_digit,
		struct s_mlx_data *mlx_data)
{
	size_t	j;

	j = 0;
	while (j < 10)
	{
		if (texture_to_img(get_num_image_location(j, counter_digit),
				*get_num_texture_location(j, &(mlx_data->textures)),
				mlx_data->mlx))
			return (1);
		j++;
	}
	return (0);
}
