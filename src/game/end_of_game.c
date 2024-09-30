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
#include "solong.h"

void    check_win_case(t_game_data *game_data) {
    if (!game_data->game_logic.remaining_collectibles)
    {
        game_data->game_logic.status = WIN;
        mlx_close_window(game_data->mlx_data.mlx);
    }
}
