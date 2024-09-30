/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:23:14 by dosokin           #+#    #+#             */
/*   Updated: 2023/12/15 19:46:15 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t strlcat(char *dst, const char *src, size_t size)
{
    size_t i_src;
    size_t i_dst;
    size_t og_len_dst;

    if (!dst || !src)
        return (0);
    og_len_dst = ft_strlen(dst);
    if (size <= og_len_dst)
        return (0);
    i_dst = og_len_dst;
    i_src = 0;
    while (src[i_src] && i_src < size - og_len_dst - 1)
    {
        dst[i_dst] = src[i_src];
        i_dst++;
        i_src++;
    }
    dst[i_dst] = 0;
    return (ft_strlen(src) + og_len_dst);
}