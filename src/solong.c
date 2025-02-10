/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 00:15:46 by jquinde-          #+#    #+#             */
/*   Updated: 2025/01/18 00:15:46 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int argc, char *argv[])
{
    int fd;
    t_matrix map;

    if (argc != 2)
    {
        write(1, MSG_ERROR_Nª_PARAMS, 73);
        return (1);
    }
    if (!is_map_valid(argv[1], &fd))
        return (0);
    map = get_matrix(fd);
    if (map.matrix == NULL)
        return (1);
    matrix_print(map);
    arr_arr_free(map.matrix, map.height);
    return (0);
}
