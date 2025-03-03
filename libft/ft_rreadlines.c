/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readlines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:29:42 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/26 18:29:42 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include <stdio.h>

void    text_to_lines(t_list **lines, char *text);

t_list  *ft_rreadlines(int fd)
{
    t_list  *lines;
	char    *text;

    text = ft_readtext(fd);
	if (text == NULL)
		return (NULL);
    lines = NULL;
    text_to_lines(&lines, text);
    /*
	n_lines = count_lines(raw_text);
	ft_putnbr_fd(n_lines, 1);
	lines = malloc(sizeof(char *) * n_lines + 1);
	if (lines == NULL)
		;
    */
    free (text);
    return (lines);
}

void    text_to_lines(t_list **lines, char *text)
{
    char    *start;
    char    *end;
    t_list  *node;

    start = text;
    while (*start != '\0')
    {
        end = start + 1;
        while (*end != '\n' && *end != '\0')
            end++;
        node = ft_lstnew(malloc(end - start + 1));
        if (node == NULL)
        {
            ft_lstclear(lines, free);
            return ;
        }
        ft_memcpy(node->content, start, end - start);
        ((char *) node->content)[end - start] = '\0';
        ft_lstadd_front(lines, node);
        start = end + (*end == '\n');
    }
}
