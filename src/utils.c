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

void	lst_to_matrix(t_list *node, char **row)
{
	size_t	j;

	j = 0;
	if (node->next != NULL)
		lst_to_matrix(node->next, row - 1);
	while (((char *)node->content)[j] != '\n' && ((char *)node->content)[j] != '\0')
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

void    fill_borders(size_t height, size_t width, char **visited)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < width)
	{
		visited[0][j] = 1; 
        visited[height - 1][j] = 1;
		j++;
	}
	i = 0;
	while (i < height)
	{
        visited[i][0] = 1;
        visited[i][width - 1] = 1;
		i++;
	}

}

void	traverse_matrix(t_matrx matrix, t_tile *spawn, char **visited)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < matrix.height - 1)
	{
		j = 1;
		while (j < matrix.width - 1)
		{
			if (matrix.data[i][j] == 'P')
			{
				spawn->i = i;
				spawn->j = j;
				visited[i][j] = 1;
			}
			if (matrix.data[i][j] == '1')
				visited[i][j] = 1;
			else
				visited[i][j] = 0;
			j++;
		}
		i++;
	}
    fill_borders(matrix.height, matrix.width, visited);
}
