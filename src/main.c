/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:23:14 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/16 15:05:29 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "solong.h"
#include <error.h>
#include <fcntl.h>
#include <stdlib.h>

void	game_loop(struct s_game_data *game_data)
{
	mlx_loop_hook(game_data->mlx_data.mlx, key_press, game_data);
	mlx_loop_hook(game_data->mlx_data.mlx, key_release, game_data);
	mlx_loop(game_data->mlx_data.mlx);
}

int	main(int argc, char *argv[])
{
	struct s_game_data	game_data;
	int					fd;

	if (argc != 2 || !argv[1] || !check_file_extension(argv[1], "ber"))
		return (error_manager(INVALID_ARGS));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (error_manager(INVALID_FILE));
	game_data = game_data_null_init();
	if (init_game(fd, &game_data))
	{
		clean_exit(&game_data);
		return (EXIT_FAILURE);
	}
	game_loop(&(game_data));
	clean_exit(&game_data);
	return (EXIT_SUCCESS);
}
