#include "header.h"

t_list *read_lines(int fd, size_t *size);
void validate_lines(t_list **lst);

    //Solo 5 caracteres: 0 1 C(>0) E(1) P(1)
    //Debe ser rectangular
    //Tiene que estar rodeado de muros
    //Tiene que haber un camino valido

t_matrix get_matrix(int fd)
{
    t_matrix map;
    t_list *lines;

    map.matrix = NULL;
    map.width = 0;
    lines = read_lines(fd, &map.width);
    if (lines == NULL)
        return (map); 
    map.height = ft_lstsize(lines);
    map.matrix = matrix_new(map.height, map.width);
    if (map.matrix == NULL)
    {
        ft_lstclear(&lines, free);
        write(1, MSG_ERROR_MALLOC_FAIL ": 4", 42);
        return (map);
    }
    lst_to_matrix(lines, map.matrix + (map.height - 1));
    ft_lstclear(&lines, free);
    if (are_borders_valid(&map))
        return (map);
    //path_validation(&map);
    return (map);
}

t_list *read_lines(int fd, size_t *size)
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
