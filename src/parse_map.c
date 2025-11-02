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

//Asserts map has a mininum of 3
void	assert_minlines(t_list *lst)
{
	if (lst->next == NULL || lst->next->next == NULL)
	{
		write(2, MSG_ERROR_MAP_FORM, 80);
		ft_lstclear(&lst, free);
		exit(EXIT_FAILURE);
	}
}

//Asserts map is rectangular and contains valid characters
void	assert_form_chars(t_list *lines)
{
	t_list	*line;
	size_t	len;

	assert_minlines(lines);
	line = lines;
	len = ft_strlen(lines->content);
	while (line != NULL)
	{
		if (len != ft_strlen(line->content))
		{
			write(2, MSG_ERROR_MAP_FORM, 80);
			ft_lstclear(&lines, free);
			exit (EXIT_FAILURE);
		}
		if (ft_strcontainsonly_str(line->content, "01EPC") == false)
		{
			write(2, MSG_ERROR_INVALID_CH, 72);
			ft_lstclear(&lines, free);
			exit (EXIT_FAILURE);
		}
		line = line->next;
	}
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

t_matrx	transform_lst_to_matrix(t_list *lines)
{
	t_matrx	matrix;

	matrix = ft_matrixinit(ft_lstsize(lines), ft_strlen(lines->content));
	if (matrix.data == NULL)
	{
		ft_lstclear(&lines, free);
		write(2, MSG_ERROR_MALLOC_FAIL, 39);
		exit (EXIT_FAILURE);
	}
	lst_to_matrix(lines, &matrix.data[matrix.height - 1]);
	ft_lstclear(&lines, free);
	return (matrix);
}

void	assert_map(int fd, t_map *map)
{
	t_list	*lines;

	assert_read(ft_rreadlines(fd, &lines));
	assert_form_chars(lines);
	map->matrix = transform_lst_to_matrix(lines);
	assert_mapborders(map->matrix);
	assert_elemcount_get_spawn_collec(map);
	assert_validpath(map);
}

