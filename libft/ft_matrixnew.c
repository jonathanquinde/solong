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

#include "libft.h"

t_matrx matrix_new(size_t height, size_t width)
{
	size_t  i;
	t_matrx t;

	t.height = 0;
	t.width = 0;
	t.data = malloc(sizeof(char *) * height);
	if (t.data == NULL)
		return (t);
	i = 0;
	while (i < height)
	{
		t.data[i] = malloc(sizeof(char) * width);
		if (t.data[i] == NULL)
		{
			arr_arr_free((void ***)&t.data, i);
			return (t);
		}
		i++;
	}
	t.height = height;
	t.width = width;
	return (t);
}
