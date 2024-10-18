/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:11:50 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/16 15:09:32 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "solong.h"
#include <stddef.h>
#include <stdlib.h>

static bool	is_empty(char *s, size_t i)
{
	if (!s)
		return (false);
	while (s[i])
	{
		if (s[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

char	**extract_map(char *brut_map)
{
	char	*truncated;
	char	**splitted;
	size_t	i;

	if (!brut_map)
		return (NULL);
	while (*brut_map == '\n')
		brut_map++;
	i = 0;
	while (brut_map[i] && !(brut_map[i] == '\n' && brut_map[i + 1] == '\n'))
		i++;
	if (!is_empty(brut_map, i))
	{
		error_manager(INVALID_MAP);
		return (NULL);
	}
	truncated = ft_strndup(brut_map, i);
	if (!truncated)
		return (NULL);
	splitted = ft_split(truncated, '\n');
	free(truncated);
	if (!splitted)
		return (NULL);
	return (splitted);
}

struct s_elements_count	count_elements(char **map)
{
	size_t					i;
	size_t					j;
	struct s_elements_count	count;

	count = elements_count_null_init();
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count.collectibles++;
			else if (map[i][j] == 'P')
				count.players++;
			else if (map[i][j] == 'E')
				count.exits++;
			else if (map[i][j] == '0')
				count.empties++;
			else if (map[i][j] != '1')
				count.others++;
			j++;
		}
	}
	return (count);
}

struct s_coord	get_element_coord(char **map, char element, size_t index)
{
	size_t			i;
	size_t			j;
	struct s_coord	element_coord;

	i = 0;
	element_coord = coord_null_init();
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == element)
				index--;
			if (!index)
			{
				element_coord.x = j;
				element_coord.y = i;
				return (element_coord);
			}
			j++;
		}
		i++;
	}
	return (element_coord);
}
