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

int	main(int argc, char *argv[])
{
	int	fd;
	t_map	map;

	fd = assert_params(argc, argv[1]);
	map = get_map(fd);
	matrix_print(map.matrix);
	arr_arr_free((void ***)&map.matrix.data, map.matrix.height);
	return (0);
}
