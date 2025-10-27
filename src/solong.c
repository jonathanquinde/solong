/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 00:15:46 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/19 15:42:36 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	assert_params(int argc, char *map_source)
{
	int	fd;

	if (argc != 2)
	{
		write(1, MSG_ERROR_N_PARAMS, 73);
		exit(EXIT_FAILURE);
	}
	if (!ft_strendswith(map_source, ".ber"))
	{
		write(1, MSG_ERROR_FILE_TYPE, 64);
		exit(EXIT_FAILURE);
	}
	fd = open(map_source, O_RDONLY);
	if (fd == -1)
	{
		write(1, MSG_ERROR_FILE_NAME, 77);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	main(int argc, char *argv[])
{
	int	fd;
	t_map	map;

	fd = assert_params(argc, argv[1]);
	map = get_map(fd);
	matrix_print(map.matrix);
	matrix_clean(&map.matrix);
	return (0);
}
