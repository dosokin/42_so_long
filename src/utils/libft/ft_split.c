/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:23:14 by dosokin           #+#    #+#             */
/*   Updated: 2023/10/30 11:24:07 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static int	count_split(char const *s, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*creation_of_char_star(char const *s, char c, int i)
{
	int		count;
	char	*r;

	count = 0;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	r = ft_calloc((count + 1), sizeof(char));
	if (!r)
		return (NULL);
	return (r);
}

static void	*caseofexit(char **r, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(r[i]);
		i++;
	}
	free(r);
	return (NULL);
}

static char	**creation_of_char_star_star(char const *s, char c, char **r)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	if (!r || !s)
        return (NULL);
    while (s[i])
	{
		k = 0;
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			r[j] = creation_of_char_star(s, c, i);
			if (!r[j])
				return (caseofexit(r, j));
			while (s[i] && s[i] != c)
				r[j][k++] = s[i++];
			j++;
		}
	}
	return (r);
}

char	**ft_split(char const *s, char c)
{
	char	**r;

	if (!s)
		return (NULL);
    r = NULL;
    r = ft_calloc((count_split(s, c) + 1), sizeof(char *));
	if (!r)
		return (NULL);
	r = creation_of_char_star_star(s, c, r);
	return (r);
}
