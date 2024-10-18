/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:11:11 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/16 12:12:22 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include <unistd.h>

int	error_manager(enum e_errors e)
{
	static char	*errors[17] = {"No errors\n", "Invalid args\n",
		"Invalid file\n", "Map not surrounded by walls\n",
		"Something wrong with the given map\n", "Memory error\n",
		"MLX error\n", "Map is not rectangular\n",
		"Error occured while reading the file\n",
		"Invalid element in the map\n", "Player is missing\n",
		"Exit is missing\n", "Missing collectibles\n", "Multiple players\n",
		"Multiple exits\n", "Impossible path\n",
		"Impossible to load texture\n"};

	if (e > 16)
		return (1);
	write(2, "Error\n", 6);
	write(2, errors[e], ft_strlen(errors[e]));
	return (1);
}
