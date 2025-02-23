/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:56:40 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/19 18:20:20 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	initialize_tiles(t_element_count *tiles)
{
	(tiles->n_collect) = 0;
	(tiles->n_exits) = 0;
	(tiles->n_spawns) = 0;
}

void	traverse_matrix(t_matrix map, t_tile *spawn, size_t *n_collections, char **visited)
{
	size_t	i;
	size_t	j;

	*n_collections = 0;
	i = 1;
	while (i < map.height - 1)
	{
		j = 1;
		while (j < map.width - 1)
		{
			if (map.matrix[i][j] == 'P')
			{
				spawn->i = i;
				spawn->j = j;
			}
			if (map.matrix[i][j] == 'C')
				(*n_collections)++;
			if (map.matrix[i][j] == '1')
				visited[i][j] = 1;
			else
				visited[i][j] = 0;
			j++;
		}
		i++;
	}
}
