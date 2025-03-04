/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raw_rreadtext.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:43:25 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/25 19:43:25 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	ft_assert_rawrreadtext(int num_bytes,t_list **head);

void	ft_raw_rreadtext(int fd, t_list **head)
{
	t_list  *node;
	int     num_bytes;

	while (1)
	{
		node = ft_lstnew_s(malloc(BUFFER_SIZE + 1));
		if (node == NULL)
		{
            write(1, "Error\nAlocacion de memoria fallida\n", 36);
			ft_lstclear(head, free);
			return ;
		}
		num_bytes = read(fd, node->content, BUFFER_SIZE);
		if (num_bytes == -1 || num_bytes == 0)
            break ;
		((char *) node->content)[num_bytes] = '\0';
		ft_lstadd_front(head, node);
	}
    ft_lstdelone(node, free);
	ft_assert_rawrreadtext(num_bytes, head);
}

void	ft_assert_rawrreadtext(int num_bytes,t_list **head)
{
	if (num_bytes == -1)
	{
		write(1, "Error\nEl archivo ya no exite\n", 30);
    	ft_lstclear(head, free);
		return ;
	}
    if (*head == NULL)
        *head = ft_lstnew(NULL);
		if (*head == NULL)
 	       write(1, "Error\nAlocacion de memoria fallida\n", 36);
}
