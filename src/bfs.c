/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:25:41 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/23 01:25:41 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	update_bfs(bool **visited, t_tile *search_tile, t_queue *queue)
{
	visited[search_tile->i][search_tile->j] = true;
	ft_queueput(queue, search_tile);
}

void	peek_tile(size_t *collected, bool *found_exit, char ch)
{
	if (ch == 'E')
		*found_exit = true;
	else if(ch == 'C')
		(*collected)--;
}

int	check_neigbours(t_tile **search_tiles, t_tile *center, bool **visited)
{
	t_tile	neighbours[4];
	size_t	i;
	size_t	j;

	fill_neighbours(neighbours, *center);
	i = 0;
	j = 0;
	while (i < 4)
	{
		if (matrx_tile((char **) visited, &neighbours[i]) == true)
		{
			i++;
			continue;
		}
		search_tiles[j] = tiledup(neighbours[i]);
		if (search_tiles[j] == NULL)
			return (MALLOC_FAIL);
		i++;
		j++;
	}
	if (j == 0)
		return (0);
	return (1);
}

int	expand(t_tile **search_tiles, t_tile *center, bool **visited)
{
	int	error_code;

	ft_bzero(search_tiles, sizeof(*search_tiles) * 4);
	error_code = check_neigbours(search_tiles, center, visited);
	free (center);
	if (error_code == MALLOC_FAIL)
	{
		arrtilesclean(search_tiles);
		return (MALLOC_FAIL);
	}
	else if (error_code == 0)
		return (0);
	return (1);
}

int	bfs(char **map, bool **visited, size_t collec,t_queue *queue)
{
	t_tile	*search_tiles[4];
	bool	found_exit;
	int		expand_status;
	size_t	i;

	found_exit = false;
	while (!ft_queueisempty(queue))
	{
		expand_status = expand(search_tiles, ft_queueget(queue), visited);
		if (expand_status == MALLOC_FAIL)
			return (MALLOC_FAIL);
		else if (expand_status == 0)
			continue;
		i = 0;
		while (i < 4 && search_tiles[i] != NULL)
		{
			peek_tile(&collec, &found_exit, matrx_tile(map, search_tiles[i]));
			update_bfs(visited, search_tiles[i], queue);
			i++;
		}
	}
	return (collec == 0 && found_exit);	
}
