/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:00:15 by jquinde-          #+#    #+#             */
/*   Updated: 2025/11/15 16:07:21 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MSG_ERROR_MALLOC_FAIL "Error\nFallo al intentar alocar memoria"
#define MSG_ERROR_FILE_TYPE "Error\nTipo de archivo invalido. Inserte un archivo de tipo .ber\n"
#define MSG_ERROR_FILE_NAME "Error\nError al intentar abrir el mapa. Compruebe que el nombre sea correcto\n"
#define MSG_ERROR_EMPTY_MAP "Error\nArchivo vacio\n"
#define MSG_ERROR_INVALID_CH "Error\nTipo de caracter invalido. Caracteres permitidos: 1, 0, E, C y P\n"
#define MSG_ERROR_N_COLECC "Error\nNumero invalido de coleccionables. Minimo un caracter C\n"
#define MSG_ERROR_N_EXITS "Error\nNumero invalido de salidas. Un unico caracter: E\n"
#define MSG_ERROR_N_SPAWNS "Error\nNumero invalido de spawns. Un unico caracter: P\n"
#define MSG_ERROR_MAP_FORM "Error\nForma del mapa invalido. Requiere un mapa rectangular de minimo 3 lineas\n"
#define MSG_ERROR_MAP_LIMITS "Error\nMapa no cerrado. Requiere un mapa rodeados de caracteres 1\n"
#define MSG_ERROR_N_PARAMS "Error\nNumero de parametros erroneo. Iniserte un solo archivo <nombre>.ber\n"
#define MSG_ERROR_PATH "Error\nEl mapa contiene una salida o collecionables no alcanzables\n"
#define MSG_ERROR "Error\n\n"

#define MALLOC_FAIL -1

#define TILE_UP(t)     ((t_tile){ (t).i - 1, (t).j })
#define TILE_RIGHT(t)  ((t_tile){ (t).i, (t).j + 1 })
#define TILE_DOWN(t)   ((t_tile){ (t).i + 1, (t).j })
#define TILE_LEFT(t)   ((t_tile){ (t).i, (t).j - 1 })

typedef struct s_tile
{
	size_t	i;
	size_t	j;
}			t_tile;

typedef struct s_map
{
	t_matrx matrix;
	size_t  n_collects;
	t_tile	player_pos;
	mlx_image_t *player_img;
}			t_map;

typedef struct s_element_count
{
	size_t	n_collect;
	size_t	n_spawns;
	size_t	n_exits;
}			t_element_count;

//Parse map
void	assert_map(int fd, t_map *map);

//Valid
void	assert_mapborders(t_matrx ptr_map);
void	assert_elemcount_get_spawn_collec(t_map *map);
void	assert_validpath(t_map *map);

//Utils
void	init_tiles(t_element_count *tiles);
void	fill_visited(t_matrx map, char **visited);
void	lst_to_matrix(t_list *node, char **row);
char	matrx_tile(char **matrix, t_tile *tile);

//Bfs utils
t_tile	*tiledup(const t_tile tile);
void	fill_neighbours(t_tile *neighbours, t_tile center);
void	arrtilesclean(t_tile **arr);

int	bfs(char **map, bool **visited, size_t n_collec,t_queue *queue);

#define TILE 16

typedef struct s_sprites
{
    mlx_image_t *empty;
    mlx_image_t *obstacle;
    mlx_image_t *exit_close;
    mlx_image_t *collect;
    mlx_image_t *player;
}   t_sprites;

void render_map(mlx_t *mlx, t_map *map);
void move_player(t_game *g, int dx, int dy);
