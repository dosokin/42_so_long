/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:13:19 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/16 08:13:21 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "solong_bonus.h"
#include <stdlib.h>
#include <unistd.h>

int	render_counter(struct s_game_data *game_data)
{
	struct s_num_images	*num_images;
	mlx_image_t			*image;
	size_t				i;
	size_t				j;

	i = 0;
	while (i < 4)
	{
		num_images = &(game_data->mlx_data.counter[i]);
		j = 0;
		while (j < 10)
		{
			image = *(get_num_image_location(j, num_images));
			mlx_image_to_window(game_data->mlx_data.mlx, image, i * 32, 0);
			if (j)
				image->enabled = false;
			j++;
		}
		i++;
	}
	return (0);
}

static int	disable_counter(struct s_game_data *game_data)
{
	struct s_num_images	*num_images;
	size_t				i;
	size_t				j;

	i = 0;
	while (i < 4)
	{
		num_images = &(game_data->mlx_data.counter[i]);
		j = 0;
		while (j < 10)
		{
			(*(get_num_image_location(j, num_images)))->enabled = false;
			j++;
		}
		i++;
	}
	return (0);
}

static int	get_len_n(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	update_counter(struct s_game_data *game_data, size_t move_count)
{
	size_t				i;
	size_t				len_n;
	struct s_num_images	*num_images;
	mlx_image_t			*image;

	if (!game_data || move_count > 1000)
		return ;
	disable_counter(game_data);
	len_n = get_len_n(move_count);
	i = 0;
	while (i < 4)
	{
		num_images = &(game_data->mlx_data.counter[3 - i]);
		if (i < len_n)
		{
			image = *(get_num_image_location(move_count % 10, num_images));
			image->enabled = true;
			move_count /= 10;
		}
		else
			(*get_num_image_location(0, num_images))->enabled = true;
		i++;
	}
}
