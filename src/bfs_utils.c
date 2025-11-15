/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- <jquinde-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:10:09 by jquinde-          #+#    #+#             */
/*   Updated: 2025/11/03 18:14:30 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	arrtilesclean(t_tile **arr)
{
	free (arr[0]);
	free (arr[1]);
	free (arr[2]);
	free (arr[3]);
	arr[0] = NULL; 
	arr[1] = NULL;
	arr[2] = NULL;
	arr[3] = NULL;
}

void	fill_neighbours(t_tile *neighbours, t_tile center)
{
	neighbours[0] = TILE_UP(center);
	neighbours[1] = TILE_RIGHT(center);
	neighbours[2] = TILE_DOWN(center);
	neighbours[3] = TILE_LEFT(center);
}

t_tile	*tiledup(const t_tile tile)
{
	t_tile *copy;

	copy = malloc(sizeof(t_tile));
	if (copy == NULL)
		return (NULL);
	*copy = tile;
	return (copy);
}
