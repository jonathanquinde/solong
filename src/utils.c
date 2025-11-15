/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:56:40 by jquinde-          #+#    #+#             */
/*   Updated: 2025/11/03 18:14:31 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	matrx_tile(char **matrix, t_tile *tile)
{
	return (matrix[tile->i][tile->j]);
}

void	lst_to_matrix(t_list *node, char **row)
{
	size_t	j;

	j = 0;
	if (node->next != NULL)
		lst_to_matrix(node->next, row - 1);
	while (((char *)node->content)[j] != '\0')
	{
		(*row)[j] = ((char *)node->content)[j];
		j++;
	}
}

void	init_tiles(t_element_count *tiles)
{
	(tiles->n_collect) = 0;
	(tiles->n_exits) = 0;
	(tiles->n_spawns) = 0;
}

void	fill_visited(t_matrx matrix, char **visited)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < matrix.height)
	{
		j = 0;
		while (j < matrix.width)
		{
			if (ft_matrixget(matrix, i, j) == '1')
				visited[i][j] = 1;
			else if (ft_matrixget(matrix, i, j) == '0')
				visited[i][j] = 0;
			j++;
		}
		i++;
	}
}
