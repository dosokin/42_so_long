/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:11:03 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/16 08:11:04 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "solong.h"

static int	check_elements_count(const struct s_elements_count elements_c)
{
	if (elements_c.others)
		return (error_manager(INVALID_ELEMENT));
	if (!elements_c.players)
		return (error_manager(MISSING_PLAYER));
	if (!elements_c.collectibles)
		return (error_manager(MISSING_COLLECTIBLE));
	if (!elements_c.exits)
		return (error_manager(MISSING_EXIT));
	if (elements_c.players > 1)
		return (error_manager(MULTI_PLAYERS));
	if (elements_c.exits > 1)
		return (error_manager(MULTI_EXITS));
	return (NO_ERRORS);
}

static int	check_lines_length(char **map)
{
	size_t	i;
	size_t	ref_length;

	if (!map || !*map)
		return (1);
	ref_length = ft_strlen(*map);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != ref_length)
			return (1);
		i++;
	}
	return (0);
}

static int	check_line_walled(char *map_line)
{
	int	i;

	if (!map_line)
		return (error_manager(MEMORY));
	i = 0;
	while (map_line[i])
	{
		if (map_line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	check_walls_surrounding(char **map)
{
	int	i;

	if (!map || !*map)
		return (error_manager(MEMORY));
	if (check_line_walled(*map))
		return (1);
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
			return (1);
		if (map[i][ft_strlen(map[i]) - 1] != '1')
			return (1);
		i++;
	}
	if (check_line_walled(map[i - 1]))
		return (1);
	return (0);
}

int	check_map_validity(char **map)
{
	if (check_elements_count(count_elements(map)))
		return (1);
	if (check_lines_length(map))
		return (error_manager(UNRECTANGULAR));
	if (check_walls_surrounding(map))
		return (error_manager(WALLS_HOLED));
	if (check_path(map))
		return (error_manager(IMPOSSIBLE_MAP));
	return (0);
}
