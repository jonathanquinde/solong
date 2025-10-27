/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixclean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- <jquinde-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:04:28 by jquinde-          #+#    #+#             */
/*   Updated: 2025/10/27 12:05:47 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	matrix_clean(t_matrx *matrix)
{
	size_t	i;

	i = 0;
	while (i < matrix->height)
	{
		free (matrix->data[i]);
		i++;
	}
	free (matrix->data);
	matrix->data = NULL;
}
