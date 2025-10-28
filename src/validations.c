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

bool	is_char_valid(unsigned char buffer, t_element_count *tiles)
{
	if (buffer == '0')
		return (true);
	else if (buffer == '1')
		return (true);
	else if (buffer == 'C')
	{
		(tiles->n_collect)++;
		return (1);
	}
	else if (buffer == 'E')
	{
		(tiles->n_exits)++;
		return (1);
	}
	else if (buffer == 'P')
	{
		(tiles->n_spawns)++;
		return (1);
	}
	else
	{
		return (0);
	}
}

int	is_line_valid(char *line, size_t width, t_element_count *tiles)
{
	size_t	len;

	len = 0;
	while (line[len] != '\n' && line[len] != '\0')
	{
		if (!is_char_valid(line[len], tiles))
		{
			write(1, MSG_ERROR_INVALID_CH, 72);
			return (0);
		}
		len++;
	}
	if (len != width)
	{
		write(1, MSG_ERROR_MAP_FORM, 80);
		return (0);
	}
	return (1);
}

int	are_borders_valid(t_matrx ptr_map)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < ptr_map.width)
	{
		if ((ptr_map.data)[0][j] != '1' || (ptr_map.data)[ptr_map.height - 1][j] != '1')
		{
			write(1, MSG_ERROR_MAP_LIMITS, 66);
			return (0);
		}
		j++;
	}
	i = 0;
	while (i < ptr_map.height)
	{
		if ((ptr_map.data)[i][0] != '1' || (ptr_map.data)[i][ptr_map.width - 1] != '1')
		{
			write(1, MSG_ERROR_MAP_LIMITS, 66);
			return (0);
		}
		i++;
	}
	return (1);
}
