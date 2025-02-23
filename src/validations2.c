/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:43:58 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/19 18:21:55 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_spawn_valid(t_matrix map)
{
	t_tile	spawn;
	size_t	n_collections;
	char	**visited;

	visited = matrix_new(map.height, map.width);
	if (visited == NULL)
		return (0);
	traverse_matrix(map, &spawn, &n_collections, visited);
	return (1);
}
