#include "header.h"

t_list *read_lines(int fd);
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
    lines = read_lines(fd);
    validate_lines(&lines);
    if (lines == NULL)
        return (map); 
    map.width = ft_strlen(lines->content);
    map.heigth = ft_lstsize(lines);
    map.matrix = matrix_new(map.heigth, map.width);
    if (map.matrix == NULL)
    {
        ft_lstclear(&lines, free);
        write(1, MSG_ERROR_MALLOC_FAIL ": 4", 42);
        return (map);
    }
    initialize_matrix(lines, map.matrix + (map.heigth - 1));
    ft_lstclear(&lines, free);
    if (are_borders_valid(&map))
        return (map);
    //path_validation(&map);
    return (map);
}

t_list *read_lines(int fd)
{
    t_list  *head;
    t_list  *new_node;
    char    *line;

    head = NULL;
    line = gnl(fd);
    if (line == NULL)
    {
        write(1, MSG_ERROR_MALLOC_FAIL ":1", 41);
        return (NULL);
    }
    while (line != NULL)
    {
        new_node = ft_lstnew(line);
        if (new_node == NULL)
        {
            ft_lstclear(&head, free);
            write(1, MSG_ERROR_MALLOC_FAIL ":2", 41);
            return (NULL);
        }
        ft_lstadd_front(&head, new_node);
        line = gnl(fd);
    } 
    if (ft_strchr(head->content, '\n'))
    {
        ft_lstclear(&head, free);
        write(1, MSG_ERROR_MALLOC_FAIL ":3", 41);
    }
    return (head);
}

void validate_lines(t_list **lst)
{
    t_list *node;
    size_t len;
    struct s_tiles tiles;

    tiles.n_collect = 0;
    tiles.n_exits = 0;
    tiles.n_spawns = 0;
    if (*lst == NULL)
        return ;
    if (ft_lstsize(*lst) == 1)
    {
        ft_lstclear(lst, free);
        write(1, MSG_ERROR_MAP_FORM, 61);
        return ;
    }
    node = *lst;
    len = ft_strlen(node->content);
    while (node->next != NULL)
    {
        if (!is_line_valid(node->content, len, &tiles))
        {
            ft_lstclear(lst, free);
            return ;
        }
        node = node->next;
    }
    are_tiles_valid(tiles);
}
