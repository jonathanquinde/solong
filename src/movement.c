/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- <jquinde-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:01:14 by jquinde-          #+#    #+#             */
/*   Updated: 2025/11/15 16:10:04 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int can_move(t_map *map, int ni, int nj)
{
    if (map->matrix.data[ni][nj] == '1')
        return 0;
    return 1;
}

void move_player(t_map *g, int dx, int dy)
{
    int ni = g->player_pos.i + dx;
    int nj = g->player_pos.j + dy;

	if (!can_move(g, ni, nj))
		return;
	// Update struct position
	g->player_pos.i = ni;
	g->player_pos.j = nj;

    // Move the image
    g->player_img->instances[0].x = nj * TILE;
    g->player_img->instances[0].y = ni * TILE;
}

