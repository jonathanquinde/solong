/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:14:25 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/19 15:21:30 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**matrix_new(size_t height, size_t width)
{
	char	**matrix;
	size_t			i;

	matrix = malloc(sizeof(char *) * height);
	if (matrix == NULL)
		return (NULL);
	i = 0;
	while (i < height)
	{
		matrix[i] = malloc(sizeof(char) * width);
		if (matrix[i] == NULL)
		{
			arr_arr_free(matrix, i - 1);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}

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

void	arr_arr_free(char **matrix, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	matrix_print(t_matrix matrix)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < matrix.height)
	{
		j = 0;
		while (j < matrix.width)
		{
			write(1, &matrix.matrix[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
