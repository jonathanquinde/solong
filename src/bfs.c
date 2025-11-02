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
#include <stdlib.h>
#include <strings.h>

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

void	arrtilesclean(t_tile **arr)
{
	free (arr[0]);
	free (arr[1]);
	free (arr[2]);
	free (arr[3]);
	arr[0] = NULL; 
	arr[1] = NULL;
	arr[2] = NULL;
	arr[3] = NULL;
}

void	expand(t_tile **search_tiles, t_tile *center, bool **visited)
{
	bzero(search_tiles, sizeof(*search_tiles) * 4);
	if (matrx_tile((char **)visited, TILE_UP(*center)) == false)
	{
		search_tiles[0]	= malloc(sizeof(t_tile));
		if (search_tiles[0] == NULL)
		{
			arrtilesclean(search_tiles);
			free (center);
		}	
		*search_tiles[0] = TILE_UP(*center);
	}
}

int	bfs(char **map, bool **visited, size_t n_collec,t_queue *queue)
{
	t_tile	*search_tiles[4];
	bool	found_exit;
	size_t	i;

	found_exit = false;
	while (!ft_queueisempty(queue))
	{
		expand(search_tiles, ft_queueget(queue), visited);
		if (search_tiles[0] == NULL)
			return (0);
		i = 0;
		while (i < 4 && search_tiles[i] != NULL)
		{
			if (matrx_tile((char **)visited, *search_tiles[i]) == true)
				free(search_tiles[i]);
			else
			{
				peek_tile(&n_collec, &found_exit, matrx_tile(map, *search_tiles[i]));
				update_bfs(visited, search_tiles[i], queue);
			}	
			i++;
		}
	}
	return (n_collec == 0 && found_exit);	
}
