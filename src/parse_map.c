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
void	validate_lines(t_list *lst, size_t width);

	//Solo 5 caracteres: 0 1 C(>0) E(1) P(1)
	//Debe ser rectangular
	//Tiene que estar rodeado de muros
	//Tiene que haber un camino valido

t_matrix	get_matrix(int fd)
{
	t_matrix	map;
	t_list		*lines;

	map.matrix = NULL;
	map.width = 0;
	lines = read_lines(fd);
	if (lines == NULL)
		exit (EXIT_FAILURE);
	//map.width = ft_strlen(lines->content);
	map.width = 18;
	validate_lines(lines, map.width);
	map.height = ft_lstsize(lines);
	map.matrix = matrix_new(map.height, map.width);
	if (map.matrix == NULL)
	{
		ft_lstclear(&lines, free);
		exit (EXIT_FAILURE);
	}
	lst_to_matrix(lines, &map.matrix[map.height - 1]);
	ft_lstclear(&lines, free);
	if (!are_borders_valid(map) || !is_spawn_valid(map))
	{
		arr_arr_free(map.matrix, map.height);
		exit (EXIT_FAILURE);
	}
	return (map);
}

void	validate_lines(t_list *lst, size_t width)
{
	t_element_count	tiles;
	t_list			*i;

	if (lst->next == NULL || lst->next->next == NULL)
	{
		write(1, MSG_ERROR_MAP_FORM, 80);
		ft_lstclear(&lst, free);
		exit(EXIT_FAILURE);
	}
	initialize_tiles(&tiles);
	i = lst;
	while (i != NULL)
	{
		if (!is_line_valid(i->content, width, &tiles))
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
}

t_list *read_lines(int fd)
{
	t_list  *head;
	t_list  *new_node;
	char    *line;

	head = NULL;
	line = gnl(fd);
	if (line == NULL)
		write(1, MSG_ERROR_EMPTY_MAP, 21);
	while (line != NULL)
	{
		new_node = ft_lstnew(line);
		ft_lstadd_front(&head, new_node);
		line = gnl(fd);
	}
	return (head);
}
