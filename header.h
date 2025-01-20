#include "include/libft.h"
#include <fcntl.h>

#define MSG_ERROR_MALLOC_FAIL "Error\nFallo al intentar alocar memoria\n"
#define MSG_ERROR_Nª_PARAMS "Error\nNumero de parametros erroneo. Inserte un solo archivo <nombre>.ber\n"
#define MSG_ERROR_FILE_TYPE "Error\nTipo de archivo invalido. Inserte un archivo de tipo .ber\n"
#define MSG_ERROR_FILE_NAME "Error\n.Error al intentar abrir el mapa. Compruebe que el nombre sea correcto\n"
#define MSG_ERROR_INVALID_CH "Error\n.Tipo de caracter invalido. Caracteres permitidos: 1, 0, E, C y P\n"
#define MSG_ERROR_Nº_COLECC "Error\n.Numero invalido de coleccionables. Minimo un caracter C\n"
#define MSG_ERROR_Nº_EXITS "Error\n.Numero invalido de salidas. Un unico caracter: E\n"
#define MSG_ERROR_Nº_SPAWNS "Error\n.Numero invalido de spawns. Un unico caracter: P\n"
#define MSG_ERROR_MAP_FORM "Error\n.Forma del mapa invalido. Requiere un mapa rectangular\n"
#define MSG_ERROR_MAP_LIMITS "Error\n.Mapa no cerrado. Requiere un mapa rodeados de caracteres: 1\n"
#define MSG_ERROR "Error\n.\n"
