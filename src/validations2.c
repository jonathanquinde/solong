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

int	is_spawn_valid(t_matrix map)
{
	int			flag;
	t_tile		*spawn;
	size_t		n_collections;
	t_matrix	visited;

	visited = matrix_new(map.height, map.width);
	if (visited.matrix == NULL)
		return (0);
	spawn = malloc(sizeof(t_tile));
	if (spawn == NULL)
		return (0);
	traverse_matrix(map, spawn, &n_collections, visited.matrix);
	visited.matrix[spawn->i][spawn->j] = 1;
	flag = bfs(map, visited.matrix, n_collections, spawn);
	if (flag == 0)
		write(1, MSG_ERROR_PATH, 67);
	arr_arr_free(visited.matrix, visited.height);
	return (flag);
}
