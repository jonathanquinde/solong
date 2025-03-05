/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrarrfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:26:00 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/25 13:26:00 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	arr_arr_free(void ***arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free((*arr)[i]);
		i++;
	}
	free(*arr);
    *arr = NULL;
}
