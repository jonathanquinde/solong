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

t_list	*read_lines(int fd);
void	validate_lines(t_list *lst, t_map *map);
void    validate_minlines(t_list *lst);
void	lst_to_matrix(t_list *node, char **row);

	//Solo 5 caracteres: 0 1 C(>0) E(1) P(1)
	//Debe ser rectangular
	//Tiene que estar rodeado de muros
	//Tiene que haber un camino valido

t_map	get_map(int fd)
{
	t_map	map;
	t_list  *lines;

	map.matrix.data = NULL;
    lines = ft_rreadlines(fd);
	if (lines == NULL)
		exit (EXIT_FAILURE);
	map.matrix.width = ft_strlen(lines->content);
	validate_lines(lines, &map);
	map.matrix = matrix_new(ft_lstsize(lines), map.matrix.width);
	if (map.matrix.data == NULL)
	{
		ft_lstclear(&lines, free);
		exit (EXIT_FAILURE);
	}
	lst_to_matrix(lines, &map.matrix.data[map.matrix.height - 1]);
	ft_lstclear(&lines, free);
	if (!are_borders_valid(map.matrix) || !is_spawn_valid(&map))
	{
		arr_arr_free(map.matrix.data, map.matrix.height);
		exit (EXIT_FAILURE);
	}
	return (map);
}

void	validate_lines(t_list *lst, t_map *map)
{
	t_element_count	tiles;
	t_list			*i;

    validate_minlines(lst);
	initialize_tiles(&tiles);
	i = lst;
	while (i != NULL)
	{
		if (!is_line_valid(i->content, (*map).matrix.width, &tiles))
		{
			ft_lstclear(&lst, free);
			exit (EXIT_FAILURE);
		}
		i = i->next;
	}
	if (!are_tiles_valid(tiles))
	{
		ft_lstclear(&lst, free);
		exit (EXIT_FAILURE);
	}
    (*map).n_collects = tiles.n_collect;
}

void    validate_minlines(t_list *lst)
{
	if (lst->next == NULL || lst->next->next == NULL)
	{
		write(1, MSG_ERROR_MAP_FORM, 80);
		ft_lstclear(&lst, free);
		exit(EXIT_FAILURE);
	}
}

void	lst_to_matrix(t_list *node, char **row)
{
	size_t	j;

	j = 0;
	if (node->next != NULL)
		lst_to_matrix(node->next, row - 1);
	while (((char *)node->content)[j] != '\n' && ((char *)node->content)[j] != '\0')
	{
		(*row)[j] = ((char *)node->content)[j];
		j++;
	}
}
