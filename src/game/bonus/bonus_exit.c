/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:14:00 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 14:35:01 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "solong_bonus.h"
#include <stdlib.h>

static void	await_esc(void *p)
{
	mlx_t	*mlx;

	mlx = p;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

static void	loss_case(void)
{
	mlx_t			*mlx;
	mlx_texture_t	*loss_texture;
	mlx_image_t		*loss_img;

	mlx = mlx_init(800, 800, "YOU LOSE", false);
	if (!mlx)
		return ;
	loss_texture = mlx_load_png("textures/bonus/loss.png");
	if (loss_texture)
	{
		loss_img = mlx_texture_to_image(mlx, loss_texture);
		if (loss_img && mlx_image_to_window(mlx, loss_img, 0, 0) >= 0)
		{
			mlx_loop_hook(mlx, await_esc, mlx);
			mlx_loop(mlx);
		}
		mlx_delete_texture(loss_texture);
	}
	mlx_terminate(mlx);
}

static void	win_case(void)
{
	mlx_t			*mlx;
	mlx_texture_t	*success_texture;
	mlx_image_t		*success_img;

	mlx = mlx_init(800, 800, "CONGRATS", false);
	if (!mlx)
		return ;
	success_texture = mlx_load_png("textures/manda/success.png");
	if (success_texture)
	{
		success_img = mlx_texture_to_image(mlx, success_texture);
		if (success_img && mlx_image_to_window(mlx, success_img, 0, 0) >= 0)
		{
			mlx_loop_hook(mlx, await_esc, mlx);
			mlx_loop(mlx);
		}
		mlx_delete_texture(success_texture);
	}
	mlx_terminate(mlx);
}

void	clean_exit(t_game_data *game_data)
{
	delete_textures(&(game_data->mlx_data.textures));
	delete_images(game_data->mlx_data, game_data->mlx_data.mlx);
	if (game_data->mlx_data.mlx)
		mlx_terminate(game_data->mlx_data.mlx);
	if (game_data->map)
		free_array(game_data->map);
	if (game_data->game_logic.status == WIN)
		win_case();
	else if (game_data->game_logic.status == LOSS)
		loss_case();
}
