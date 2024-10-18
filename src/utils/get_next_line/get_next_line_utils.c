/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:59:56 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/16 08:08:07 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strjoin_special(char *a, char *b)
{
	int		i;
	int		j;
	char	*joined;

	if (!a || !b)
		return (NULL);
	joined = malloc((ft_strlen(a) + ft_strlen(b) + 1) * sizeof(char));
	if (joined)
	{
		i = 0;
		j = 0;
		while (a[i])
			joined[j++] = a[i++];
		i = 0;
		while (b[i])
			joined[j++] = b[i++];
		joined[j] = 0;
	}
	free(a);
	free(b);
	return (joined);
}

int	find_new_line(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
}
