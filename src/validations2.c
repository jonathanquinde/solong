/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:43:58 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/19 18:21:55 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

t_bool  is_spawn_valid(t_map *map)
{
	t_bool	flag;
	t_tile	*spawn;
	t_matrx	visited;
    t_queue queue;

	visited = matrix_new(map->matrix.height, map->matrix.width);
	if (visited.data == NULL)
		return (false);
	spawn = malloc(sizeof(t_tile));
	if (spawn == NULL)
    {
	    arr_arr_free((void ***)&visited.data, visited.height);
		return (false);
    }
	traverse_matrix(map->matrix, spawn, visited.data);
	queue = queue_new();
	queue_put(&queue, spawn);
	flag = bfs(map, visited.data, &queue);
	if (flag == false)
		write(1, MSG_ERROR_PATH, 67);
    queue_free(&queue);
	arr_arr_free((void ***)&visited.data, visited.height);
	return (flag);
}
