/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:59:16 by dosokin           #+#    #+#             */
/*   Updated: 2023/12/15 20:02:42 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

enum e_errors{
    NO_ERRORS,
    INVALID_ARGS,
    INVALID_FILE,
    WALLS_HOLED,
    INVALID_MAP,
    MEMORY,
    MLX,
    UNRECTANGULAR,
    READ_ISSUE,
    INVALID_ELEMENT,
    MISSING_PLAYER,
    MISSING_EXIT,
    MISSING_COLLECTIBLE,
    MULTI_PLAYERS,
    MULTI_EXITS,
    IMPOSSIBLE_MAP,
    TEXTURES,
};

int	error_manager(enum e_errors e);