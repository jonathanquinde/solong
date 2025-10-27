/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:10:08 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/19 18:18:14 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

	//Solo 5 caracteres: 0 1 C(>0) E(1) P(1)
	//Debe ser rectangular
	//Tiene que estar rodeado de muros
	//Tiene que haber un camino valido

void	assert_minlines(t_list *lst)
{
    if (lst->next == NULL || lst->next->next == NULL || lst->next->next->next == NULL)
    {
        write(1, MSG_ERROR_MAP_FORM, 80);
        ft_lstclear(&lst, free);
        exit(EXIT_FAILURE);
    }
}

int	check_len_count_tiles(t_list *lines, t_element_count *tiles)
{
	t_list	*line;
	size_t	len;

	line = lines;
	len = ft_strlen(lines->content);
	while (line != NULL)
	{
		if (!is_line_valid(line->content, len, tiles))
		{
			return (0);
		}
		line = line->next;
	}
	return (1);
}

int	are_tiles_valid(t_element_count tiles)
{
	if (tiles.n_exits != 1)
	{
		write(1, MSG_ERROR_N_EXITS, 56);
		return (0);
	}
	if (tiles.n_spawns != 1)
	{
		write(1, MSG_ERROR_N_SPAWNS, 55);
		return (0);
	}
	if (tiles.n_collect < 1)
	{
		write(1, MSG_ERROR_N_COLECC, 63);
		return (0);
	}
	return (1);
}

void	assert_lines(t_list *lines, size_t *num_collects)
{
	t_element_count	tiles;

	assert_minlines(lines);
	init_tiles(&tiles);
	if (!check_len_count_tiles(lines, &tiles))
	{
		ft_lstclear(&lines, free);
		exit (EXIT_FAILURE);
	}
	if (!are_tiles_valid(tiles))
	{
		ft_lstclear(&lines, free);
		exit (EXIT_FAILURE);
	}
	*num_collects = tiles.n_collect;
}

void	assert_read(int read_status)
{
	if (read_status == READ_SUCCESS)
		return ;
	else if (read_status == READ_EMPTY)
	{
		write(2, MSG_ERROR_EMPTY_MAP, 21);
		exit(EXIT_FAILURE);
	}
	//TODO: Cambiar mensaje de error, fallo al leer el archivo
	else if (read_status == READ_FAIL)
	{
		write(2, MSG_ERROR_FILE_NAME, 39);
		exit(EXIT_FAILURE);
	}
	else if (read_status == READ_FAIL_MALLOC)
	{
		write(2, MSG_ERROR_MALLOC_FAIL, 39);
		exit(EXIT_FAILURE);
	}
}

t_map	get_map(int fd)
{
	int		read_status;
	t_list	*lines;
	t_map	map;

	read_status = ft_rreadlines(fd, &lines);
	assert_read(read_status);
	assert_lines(lines, &map.n_collects);
	map.matrix = matrix_new(ft_lstsize(lines), ft_strlen(lines->content));
	if (map.matrix.data == NULL)
	{
		ft_lstclear(&lines, free);
		write(2, MSG_ERROR_MALLOC_FAIL, 39);
		exit (EXIT_FAILURE);
	}
	lst_to_matrix(lines, &map.matrix.data[map.matrix.height - 1]);
	ft_lstclear(&lines, free);
	if (!are_borders_valid(map.matrix) || !is_spawn_valid(&map))
	{
		matrix_clean(&map.matrix);
		exit (EXIT_FAILURE);
	}
	return (map);
}
