#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#define MSG_ERROR_MALLOC_FAIL "Error\nFallo al intentar alocar memoria"
#define MSG_ERROR_Nª_PARAMS "Error\nNumero de parametros erroneo. Inserte un solo archivo <nombre>.ber\n"
#define MSG_ERROR_FILE_TYPE "Error\nTipo de archivo invalido. Inserte un archivo de tipo .ber\n"
#define MSG_ERROR_FILE_NAME "Error\nError al intentar abrir el mapa. Compruebe que el nombre sea correcto\n"
#define MSG_ERROR_EMPTY_MAP "Error\nArchivo vacio\n"
#define MSG_ERROR_INVALID_CH "Error\nTipo de caracter invalido. Caracteres permitidos: 1, 0, E, C y P\n"
#define MSG_ERROR_Nº_COLECC "Error\nNumero invalido de coleccionables. Minimo un caracter C\n"
#define MSG_ERROR_Nº_EXITS "Error\nNumero invalido de salidas. Un unico caracter: E\n"
#define MSG_ERROR_Nº_SPAWNS "Error\nNumero invalido de spawns. Un unico caracter: P\n"
#define MSG_ERROR_MAP_FORM "Error\nForma del mapa invalido. Requiere un mapa rectangular\n"
#define MSG_ERROR_MAP_LIMITS "Error\nMapa no cerrado. Requiere un mapa rodeados de caracteres 1\n"
#define MSG_ERROR "Error\n\n"

typedef struct s_matrix
{
	unsigned char **matrix;
	size_t width;
	size_t height;
}              t_matrix;

struct s_tiles
{
	size_t n_collect;
	size_t n_spawns;
	size_t n_exits;
};

t_matrix get_matrix(int fd);

int is_line_valid(char *current, size_t *width, struct s_tiles *tiles);
int are_params_valid(int argc, char *map_source);
int are_tiles_valid(struct s_tiles tiles);
int are_borders_valid(t_matrix *ptr_map);

unsigned char **matrix_new(size_t height, size_t width);
void	lst_to_matrix(t_list *node, unsigned char **row);
void arr_arr_free(unsigned char **matrix, size_t size);
void    matrix_print(t_matrix matrix);

void initialize_tiles(struct s_tiles *tiles);

char    *gnl(int fd);