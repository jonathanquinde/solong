/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 00:24:44 by jquinde-          #+#    #+#             */
/*   Updated: 2025/01/23 00:24:44 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int is_char_valid(unsigned char buffer, struct s_tiles *tiles)
{
    if (buffer == '0')
        return (1);
    if (buffer == '1')
        return (1);
    if (buffer == 'C')
    {
        (tiles->n_collect)++;
        return (1);
    }
    if (buffer == 'E')
    {
        (tiles->n_exits)++;
        return (1);
    }
    if (buffer == 'P')
    {
        (tiles->n_spawns)++;
        return (1);
    }
    write(1, MSG_ERROR_INVALID_CH, 72);
    return (0);
}

int is_line_valid(unsigned char *current, size_t width, struct s_tiles *tiles)
{
    size_t len1;

    len1 = 0;
    while (current[len1] != '\n' && current[len1] != '\0' && current[len1] != '\r')
    {
        if (!is_char_valid(current[len1], tiles))
            return(0);
        len1++;
    }
    if (len1 != width)
    {
        write(1, MSG_ERROR_MAP_FORM, 61);
        return (0);
    }
    return (1);
}

int are_tiles_valid(struct s_tiles tiles)
{
    if (tiles.n_exits != 1)
    {
        write(1, MSG_ERROR_Nº_EXITS, 56);
        return (0);
    }
    if (tiles.n_spawns != 1)
    {
        write(1, MSG_ERROR_Nº_SPAWNS, 55);
        return (0);
    }
    if (tiles.n_collect < 1)
    {
        write(1, MSG_ERROR_Nº_COLECC, 63);
        return (0);
    }
    return (1);
}

int is_map_valid(const char *map_source, int *fd)
{
    char *ptr;

    ptr = ft_strrchr(map_source, '.');
    if (ptr == NULL)
    {
        write(1, MSG_ERROR_FILE_TYPE, 64);
        return (0);
    }
    if (ft_strncmp(ptr, ".ber", 4))
    {
        write(1, MSG_ERROR_FILE_TYPE, 64);
        return (0);
    }
    *fd = open(map_source, O_RDONLY);
    if (*fd == -1)
    {
        write (1, MSG_ERROR_FILE_NAME, 77);
        return (0);
    }
    return 1;
}

int are_borders_valid(t_matrix *ptr_map)
{
    size_t i;
    size_t j;

    j = 0;
    while (j < ptr_map->width)
    {
        if ((ptr_map->matrix)[0][j] != '1' && (ptr_map->matrix)[ptr_map->heigth - 1][j])
        {
            arr_arr_free(ptr_map->matrix, ptr_map->heigth);
            ptr_map->matrix = NULL;
            write(1, MSG_ERROR_MAP_LIMITS, 61);
            return (0);
        }
        j++;
    }
    i = 0;
    while (i < ptr_map->heigth)
    {
        if ((ptr_map->matrix)[i][0] != '1' && (ptr_map->matrix)[i][ptr_map->width - 1])
        {
            arr_arr_free(ptr_map->matrix, ptr_map->heigth);
            ptr_map->matrix = NULL;
            write(1, MSG_ERROR_MAP_LIMITS, 61);
            return (0);
        }
        i++;
    }
    return (1);
}
