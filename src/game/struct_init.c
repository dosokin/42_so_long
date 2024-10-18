/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:05:55 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 14:32:58 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

struct s_elements_count	elements_count_null_init(void)
{
	struct s_elements_count	count;

	count.collectibles = 0;
	count.players = 0;
	count.exits = 0;
	count.empties = 0;
	count.others = 0;
	return (count);
}

struct s_coord	coord_null_init(void)
{
	struct s_coord	element_coord;

	element_coord.x = 0;
	element_coord.y = 0;
	return (element_coord);
}

struct s_keys_status	key_status_null_init(void)
{
	struct s_keys_status	keys_status;

	keys_status.down = RELEASED;
	keys_status.up = RELEASED;
	keys_status.left = RELEASED;
	keys_status.right = RELEASED;
	return (keys_status);
}

struct s_game_logic	game_logic_null_init(void)
{
	struct s_game_logic	game_logic;

	game_logic.player = coord_null_init();
	game_logic.remaining_collectibles = 0;
	game_logic.status = DEFAULT;
	game_logic.keys_status = key_status_null_init();
	return (game_logic);
}
