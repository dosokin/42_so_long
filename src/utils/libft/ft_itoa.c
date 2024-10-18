/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:09:29 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/16 08:09:30 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_len_n(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*converted;
	int		len_n;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len_n = get_len_n(n);
	converted = malloc((len_n + 1) * sizeof(char));
	if (!converted)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		converted[0] = '-';
	}
	i = len_n;
	converted[i--] = 0;
	while (n / 10 > 0)
	{
		converted[i--] = n % 10 + '0';
		n /= 10;
	}
	converted[i--] = n % 10 + '0';
	return (converted);
}
