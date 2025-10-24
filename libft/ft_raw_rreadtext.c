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
#include <stdlib.h>
#include <unistd.h>

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

//todo: Quitar printeo de errores.
void	ft_raw_rreadtext(int fd, t_list **head)
{
	t_list	*node;
	ssize_t	bytes_read;
	char	*read_buffer;

	read_buffer = malloc(BUFFER_SIZE + 1);
	if (read_buffer == NULL)
	{
			write(1, "Error\nAlocacion de memoria fallida\n", 36);
			ft_lstclear(head, free);
			return ;
	}
	while (1)
	{
		bytes_read = read(fd, read_buffer ,BUFFER_SIZE); 
		if (bytes_read == -1 || bytes_read == 0)
			break ;
		read_buffer[bytes_read] = '\0';
		node = ft_lstnew_s(ft_strdup(read_buffer));
		if (node == NULL || node->content == NULL)
		{
			write(1, "Error\nAlocacion de memoria fallida\n", 36);
			ft_lstclear(head, free);
			return ;
		}
		ft_lstadd_front(head, node);
	}
	ft_assert_rawrreadtext(bytes_read, head);
}

