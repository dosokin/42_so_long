/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:23:14 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/16 08:10:03 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*dupe;

	if (!s)
	{
		return (NULL);
	}
	dupe = malloc(ft_strlen(s) + 1);
	if (!dupe)
		return (NULL);
	i = 0;
	while (s[i] && i < n)
	{
		dupe[i] = s[i];
		i++;
	}
	dupe[i] = 0;
	return (dupe);
}
