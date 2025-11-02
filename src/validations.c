/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 00:24:44 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/19 18:17:00 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static bool	are_borders_valid(t_matrx matrix)
{
	size_t	i;

	i = 0;
	while (i < matrix.height)
	{
		if (ft_matrixget(matrix, i, 0) != '1')
			return (false);
		if (ft_matrixget(matrix, i, matrix.width - 1) != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < matrix.width)
	{
		if (ft_matrixget(matrix, 0, i) != '1')
			return (false);
		if (ft_matrixget(matrix, matrix.height - 1, i) != '1')
			return (false);
		i++;
	}
	return (true);
}

void	assert_mapborders(t_matrx matrix)
{
	if (are_borders_valid(matrix) == false)
	{
		write(STDERR_FILENO, MSG_ERROR_MAP_LIMITS, 66);
		ft_matrixclean(&matrix);
		exit(EXIT_FAILURE);
	}
}

static bool	are_tiles_valid(t_element_count tiles)
{
	if (tiles.n_exits != 1)
	{
		write(STDERR_FILENO, MSG_ERROR_N_EXITS, 56);
		return (false);
	}
	if (tiles.n_spawns != 1)
	{
		write(STDERR_FILENO, MSG_ERROR_N_SPAWNS, 55);
		return (false);
	}
	if (tiles.n_collect < 1)
	{
		write(STDERR_FILENO, MSG_ERROR_N_COLECC, 63);
		return (false);
	}
	return (true);
}

static t_element_count	count_elements(t_matrx matrix, t_tile *player_pos)
{
	t_element_count	elements;
	size_t			i;
	size_t			j;

	i = 0;
	init_tiles(&elements);
	while (i < matrix.height)
	{
		j = 0;
		while (j < matrix.width)
		{
			if (ft_matrixget(matrix, i, j) == 'C')
				elements.n_collect++;
			else if (ft_matrixget(matrix, i, j) == 'P')
			{
				*player_pos = (t_tile){i, j};
				elements.n_spawns++;
			}
			else if (ft_matrixget(matrix, i, j) == 'E')
				elements.n_exits++;
			j++;
		}
		i++;
	}
	return (elements);
}

void	assert_elemcount_get_spawn_collec(t_map *map)
{
	t_element_count	elements;

	elements = count_elements(map->matrix, &map->player_pos);
	if (are_tiles_valid(elements) == false)
	{
		ft_matrixclean(&map->matrix);
		exit(EXIT_FAILURE);
	}
	map->n_collects = elements.n_collect;
}

