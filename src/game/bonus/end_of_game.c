/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 01:47:35 by dosokin           #+#    #+#             */
/*   Updated: 2024/09/30 01:55:04 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "solong_bonus.h"

void	check_death_case(void *p)
{
    t_game_data *game_data;

    game_data = p;
    if (game_data->game_logic.player.x == game_data->game_logic.enemy.x)
    {
        if (game_data->game_logic.player.y == game_data->game_logic.enemy.y)
        {
            game_data->game_logic.status = LOSS;
            mlx_close_window(game_data->mlx_data.mlx);
        }
    }
}

void    check_win_case(t_game_data *game_data) {
    if (!game_data->game_logic.remaining_collectibles)
    {
        game_data->game_logic.status = WIN;
        mlx_close_window(game_data->mlx_data.mlx);
    }
}
