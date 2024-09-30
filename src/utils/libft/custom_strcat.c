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
#include <stdlib.h>

char *custom_strcat(char *s1, char *s2){
    size_t i_src;
    size_t i_dst;
    char *destination;

    if (!s1 || !s2)
        return (NULL);
    i_src = 0;
    i_dst = 0;
    destination = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!destination)
        return (NULL);
    while (s1[i_src])
        destination[i_dst++] = s1[i_src++];
    i_src = 0;
    while (s2[i_src])
        destination[i_dst++] = s2[i_src++];
    destination[i_dst] = 0;
    return (destination);
}