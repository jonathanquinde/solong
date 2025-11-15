/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 00:15:46 by jquinde-          #+#    #+#             */
/*   Updated: 2025/11/15 16:01:06 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

int	assert_params(int argc, char *map_source)
{
	int	fd;

	if (argc != 2)
	{
		write(2, MSG_ERROR_N_PARAMS, 73);
		exit(EXIT_FAILURE);
	}
	if (!ft_strendswith(map_source, ".ber"))
	{
		write(2, MSG_ERROR_FILE_TYPE, 64);
		exit(EXIT_FAILURE);
	}
	fd = open(map_source, O_RDONLY);
	if (fd == -1)
	{
		write(2, MSG_ERROR_FILE_NAME, 77);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void key_hook(mlx_key_data_t keydata, void *param)
{
    t_game *g = (t_game *)param;

    if (keydata.action != MLX_PRESS)
        return;

    if (keydata.key == MLX_KEY_ESCAPE)
        mlx_close_window(g->mlx);

    if (keydata.key == MLX_KEY_UP)
        move_player(g, 0, -1);
    if (keydata.key == MLX_KEY_DOWN)
        move_player(g, 0, 1);
    if (keydata.key == MLX_KEY_LEFT)
        move_player(g, -1, 0);
    if (keydata.key == MLX_KEY_RIGHT)
        move_player(g, 1, 0);
}

int	main(int argc, char *argv[])
{
	int	fd;
	t_map	map;

	fd = assert_params(argc, argv[1]);
	assert_map(fd, &map);
	ft_matrixprint(map.matrix);
	mlx_t *mlx = mlx_init(map.matrix.height * TILE, map.matrix.height * TILE, "so_long", false);
    if (!mlx)
	{
		ft_matrixclean(&map.matrix);
		return (EXIT_FAILURE);
	}
    render_map(mlx, &g_map);

	mlx_key_hook(game.mlx, &key_hook, &game);

    mlx_loop(mlx);
    mlx_terminate(mlx);
	ft_matrixclean(&map.matrix);
	return (0);
}
