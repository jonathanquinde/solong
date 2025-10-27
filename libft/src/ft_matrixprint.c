/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:28:31 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/25 13:28:31 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	matrix_print(t_matrx matrix)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < matrix.height)
	{
		j = 0;
		while (j < matrix.width)
		{
			write(1, &matrix.data[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
