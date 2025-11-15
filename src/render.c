/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- <jquinde-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:35:09 by jquinde-          #+#    #+#             */
/*   Updated: 2025/11/15 16:11:54 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void load_sprites(mlx_t *mlx, t_sprites *sp)
{
    sp->empty      = mlx_texture_to_image(mlx, mlx_load_xpm42("textures/empty.xpm42"));
    sp->obstacle   = mlx_texture_to_image(mlx, mlx_load_xpm42("textures/obstacle.xpm42"));
    sp->exit_close = mlx_texture_to_image(mlx, mlx_load_xpm42("textures/exit_close.xpm42"));
    sp->collect    = mlx_texture_to_image(mlx, mlx_load_xpm42("textures/collectable.xpm42"));
    sp->player     = mlx_texture_to_image(mlx, mlx_load_xpm42("textures/player_up1.xpm42"));

    if (!sp->empty || !sp->obstacle || !sp->exit_close
        || !sp->collect || !sp->player)
    {
        puts("Error: Failed loading textures");
        exit(EXIT_FAILURE);
    }
}

static void put_tile(mlx_t *mlx, char c, t_sprites *sp, int x, int y)
{
    if (c == '0')
        mlx_image_to_window(mlx, sp->empty,      x * TILE, y * TILE);
    else if (c == '1')
        mlx_image_to_window(mlx, sp->obstacle,   x * TILE, y * TILE);
    else if (c == 'E')
        mlx_image_to_window(mlx, sp->exit_close, x * TILE, y * TILE);
    else if (c == 'C')
        mlx_image_to_window(mlx, sp->collect,    x * TILE, y * TILE);
    else if (c == 'P')
        mlx_image_to_window(mlx, sp->player,     x * TILE, y * TILE);
}

void render_map(mlx_t *mlx, t_map *map)
{
    t_sprites sp;
    load_sprites(mlx, &sp);

    map->player_img = sp.player;
    for (size_t y = 0; y < map->matrix.height; y++)
    {
        for (size_t x = 0; x < map->matrix.width; x++)
        {
            put_tile(mlx, map->matrix.data[y][x], &sp, x, y);
        }
    }
}
