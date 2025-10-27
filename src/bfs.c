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

void	update_bfs(char **visited, t_tile *search_tile, t_queue *queue)
{
	visited[search_tile->i][search_tile->j] = 1;
	queue_put(queue, search_tile);
}

void	peek_tile(size_t *collected, int *found_exit, char ch)
{
	if (ch == 'E')
		*found_exit = 1;
	else if(ch == 'C')
		(*collected)++;
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

void	expand(t_tile **search_tiles, t_tile *search_tile)
{
	search_tiles[0] = NULL;  
	search_tiles[1] = NULL; 
	search_tiles[2] = NULL; 
	search_tiles[3] = NULL; 
	search_tiles[0] = malloc(sizeof(t_tile));
	search_tiles[1] = malloc(sizeof(t_tile));
	search_tiles[2] = malloc(sizeof(t_tile));
	search_tiles[3] = malloc(sizeof(t_tile));
	if (search_tiles[0] == NULL || search_tiles[1] == NULL || search_tiles[2] == NULL || search_tiles[3] == NULL)
	{
		free (search_tile);
		arrtilesclean(search_tiles);
		return ;
	}
	search_tiles[0]->i = search_tile->i - 1;
	search_tiles[0]->j = search_tile->j;
	search_tiles[1]->i = search_tile->i;
	search_tiles[1]->j = search_tile->j + 1;
	search_tiles[2]->i = search_tile->i + 1;
	search_tiles[2]->j = search_tile->j;
	search_tiles[3]->i = search_tile->i;
	search_tiles[3]->j = search_tile->j - 1;
	free (search_tile);
}

void	initialize_collec_foundext(size_t *collec, int *found_exit)
{
	*collec = 0;
	*found_exit = 0;
}

int	bfs(t_map *map, char **visited, t_queue *queue)
{
	t_tile	*search_tiles[4];
	size_t	collected;
	int  found_exit;
	size_t	i;

	initialize_collec_foundext(&collected, &found_exit);
	while (!queue_empty(*queue))
	{
		expand(search_tiles, queue_get(queue));
		if (search_tiles[0] == NULL)
			return (0);
		i = 0;
		while (i < 4)
		{
			if (visited[search_tiles[i]->i][search_tiles[i]->j])
				free(search_tiles[i]);
			else
			{
				peek_tile(&collected, &found_exit, map->matrix.data[search_tiles[i]->i][search_tiles[i]->j]);
				update_bfs(visited, search_tiles[i], queue);
			}	
			i++;
		}
	}
	return (collected == map->n_collects && found_exit);	
}
