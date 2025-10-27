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

int	is_spawn_valid(t_map *map)
{
	int		flag;
	t_tile	*spawn;
	t_matrx	visited;
	t_queue queue;

	visited = matrix_new(map->matrix.height, map->matrix.width);
	if (visited.data == NULL)
		return (0);
	spawn = malloc(sizeof(t_tile));
	if (spawn == NULL)
	{
		matrix_clean(&visited);
		return (0);
	}
	traverse_matrix(map->matrix, spawn, visited.data);
	queue = queue_new();
	queue_put(&queue, spawn);
	flag = bfs(map, visited.data, &queue);
	if (flag == 0)
		write(1, MSG_ERROR_PATH, 67);
	queue_free(&queue);
	matrix_clean(&visited);
	return (flag);
}
