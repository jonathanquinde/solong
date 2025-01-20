#include "header.h"

t_list  *get_lines(t_list **head, int fd);
unsigned char *get_first_line(int fd, size_t *width);
void array_add(void **arr, void *element, size_t *size, size_t elem_size);
int is_char_valid(unsigned char buffer);

    //Solo 5 caracteres: 0 1 C(>0) E(1) P(1)
    //Debe ser rectangular
    //Tiene que estar rodeado de muros
    //Tiene que haber un camino valido

t_list *validate_map(const char *map_source)
{
    t_list          *head;
    unsigned char   *arr;
    int             fd;
    size_t          width;

    if (ft_strncmp(ft_strrchr(map_source, '.'), ".ber", 4))
    {
        write(1, MSG_ERROR_FILE_TYPE, 64);
        return (NULL);
    }
    fd = open(map_source, O_RDONLY);
    if (fd == -1)
    {
        write (1, MSG_ERROR_FILE_NAME, 77);
        return (NULL);
    }
    arr = get_first_line(fd, &width);
    if (arr == NULL)
        return (NULL);
    head = ft_lstnew(arr);
    if (head != NULL)
        return (get_lines(&head, fd, width));
    write (1, MSG_ERROR_FILE_NAME, 77);
    free (arr);
    return (NULL);
}

t_list  *get_lines(t_list **head, int fd, size_t width)
{
    unsigned char *arr;
    unsigned char buffer;
    

    return (*head);
}

unsigned char *get_first_line(int fd, size_t *width)
{
    struct sp_arr   *arr;
    unsigned char	buffer;

    arr = NULL;
    *width = 0;
    read(fd, &buffer, 1);
    while (buffer != '\n')
    {
        if (is_char_valid(buffer))
        {
            free (arr);
            return (NULL);
        }
        array_add((void **)(&arr), &buffer, width, 1);
        if (arr == NULL)
            return (NULL);
    }
    if (buffer == '\n')
        return (arr);
    free (arr);
    write (1, MSG_ERROR_MAP_FORM, 61);
    return (NULL);
}

void array_add(void **arr, void *element, size_t *size, size_t elem_size)
{
    void    *new_arr;

    if (*arr == NULL)
    {
        *arr = malloc(elem_size);
        if (*arr == NULL)
            write(1, MSG_ERROR_MALLOC_FAIL, 39);
    }
    else
    {
        new_arr = malloc(*size + elem_size);
        if (new_arr == NULL)
        {
            write(1, MSG_ERROR_MALLOC_FAIL, 39);
            free(*arr);
            *arr = NULL;
            return ;
        }
        ft_memcpy(new_arr, *arr, *size * elem_size);
        ft_memcpy((char *)new_arr + (*size * elem_size), element, elem_size);
        free(*arr);
        *arr = new_arr;
    }
    (*size)++;
}

int is_char_valid(unsigned char buffer)
{
    if (buffer == '0')
        return (1);
    else if (buffer == '1')
        return (1);
    else if (buffer == 'C')
        return (1);
    else if (buffer == 'E')
        return (1);
    else if (buffer == 'P')
        return (1);
    write(1, MSG_ERROR_INVALID_CH, 72);
    return (0);
}