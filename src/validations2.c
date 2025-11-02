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

static void	create_visited(t_map *map, t_matrx *visited)
{
	*visited = ft_matrixinit(map->matrix.height, map->matrix.width);
	if (visited->data == NULL)
	{
		write(2, MSG_ERROR_MALLOC_FAIL, 39);
		ft_matrixclean(&map->matrix);
		exit(EXIT_FAILURE);
	}
	traverse_matrix(map->matrix, visited->data);
	visited->data[map->player_pos.i][map->player_pos.j] = 1;
}

static void	create_spawn_tile(t_map *map, t_matrx *visited, t_tile **spawn_pos)
{
	*spawn_pos = malloc(sizeof(t_tile));
	if (spawn_pos == NULL)
	{
		ft_matrixclean(&map->matrix);
		ft_matrixclean(visited);
		write(2, MSG_ERROR_MALLOC_FAIL, 39);
		exit(EXIT_FAILURE);
	}
	(*spawn_pos)->i = map->player_pos.i;
	(*spawn_pos)->j = map->player_pos.j;
}

void	assert_validpath(t_map *map)
{
	bool	valid;
	t_tile	*spawn_pos;
	t_queue *queue;
	t_matrx	visited;

	create_visited(map, &visited);
	create_spawn_tile(map, &visited, &spawn_pos);
	queue = ft_queuenew();
	ft_queueput(queue, spawn_pos);
	valid = bfs(map->matrix.data, (bool **)visited.data, map->n_collects, queue);
	ft_queueclean(queue);
	ft_matrixclean(&visited);
	if (valid == false)
	{
		ft_matrixclean(&map->matrix);
		write(2, MSG_ERROR_PATH, 67);
		exit(EXIT_FAILURE);
	}
}
