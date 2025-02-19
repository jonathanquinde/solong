/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:56:40 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/19 17:36:39 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	initialize_tiles(t_element_count *tiles)
{
	(tiles->n_collect) = 0;
	(tiles->n_exits) = 0;
	(tiles->n_spawns) = 0;
}

void	find_spawn(t_matrix map, size_t *x, size_t *y)
{
	size_t	i;
	size_t	j;

	i = 0;
	printf("%zu %zu", map.height, map.width);
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (map.matrix[i][j] == 'P')
			{
				*y = i;
				*x = j;
				return ;
			}
			i++;
			j++;
		}
	}
}
