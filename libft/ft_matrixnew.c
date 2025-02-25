/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:23:42 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/25 13:23:42 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix matrix_new(size_t height, size_t width)
{
	size_t		i;
	t_matrix	t;

	t.height = 0;
	t.width = 0;
	t.matrix = malloc(sizeof(char *) * height);
	if (t.matrix == NULL)
		return (t);
	i = 0;
	while (i < height)
	{
		t.matrix[i] = malloc(sizeof(char) * width);
		if (t.matrix[i] == NULL)
		{
			arr_arr_free(t.matrix, i);
			return (t);
		}
		i++;
	}
	t.height = height;
	t.width = width;
	return (t);
}
