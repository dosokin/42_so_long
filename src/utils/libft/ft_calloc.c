/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:23:14 by dosokin           #+#    #+#             */
/*   Updated: 2023/11/04 20:57:39 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static void	ft_bzero(void *s, size_t n)
{
    unsigned char	*p;
    size_t			i;

    if (!s)
        return;
    p = s;
    i = 0;
    while (i < n)
    {
        p[i] = 0;
        i++;
    }
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*t;

	if (size != 0)
	{
		if (2147483647 / size < nmemb)
			return (NULL);
	}
	if (nmemb != 0)
	{
		if (2147483647 / nmemb < size)
			return (NULL);
	}
	t = malloc(nmemb * size);
	if (!t)
		return (NULL);
	ft_bzero(t, nmemb * size);
	return (t);
}
