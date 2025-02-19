/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:56:40 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/19 13:56:47 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	initialize_tiles(struct s_tiles *tiles)
{
	(tiles->n_collect) = 0;
	(tiles->n_exits) = 0;
	(tiles->n_spawns) = 0;
}
