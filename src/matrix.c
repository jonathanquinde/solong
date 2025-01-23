/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:14:25 by jquinde-          #+#    #+#             */
/*   Updated: 2025/01/21 19:14:25 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned char **matrix_new(size_t height, size_t width)
{
    unsigned char **matrix;
    size_t      i;

    matrix = malloc(sizeof(unsigned char *) * height);
    if (matrix == NULL)
        return (NULL);
    i = 0;
    while (i < height)
    {
        matrix[i] = malloc(sizeof(unsigned char) * width); 
        if (matrix[i] == NULL)
        {
            arr_arr_free(matrix, i - 1);
            return (NULL);
        }
        i++;
    }
    return (matrix);
}

void    initialize_matrix(t_list *node, unsigned char **row)
{
    size_t j;

    j = 0;
    if (node->next != NULL)
        initialize_matrix(node->next, row - 1);
    while (((unsigned char *)node->content)[j] != '\n' && ((unsigned char *)node->content)[j] != '\r' && ((unsigned char *)node->content)[j] != '\0')
    {
        (*row)[j] = ((unsigned char *)node->content)[j];
        j++;
    }
    
}

void    arr_arr_free(unsigned char **matrix, size_t size)
{
    size_t i;

    i = 0;
    while (i < size)
    {
        free(matrix[i]);
        i++;;
    }
    free(matrix);
}

void    matrix_print(t_matrix matrix)
{
    size_t i;
    size_t j;

    i = 0;
    while (i < matrix.heigth)
    {
        j = 0;
        while (j < matrix.width)
        {
            write(1, &matrix.matrix[i][j], 1);
            j++; 
        }
        write(1, "\n", 1);
        i++;
    }
}
