/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readtext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:43:11 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/20 18:43:11 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *readtext(int fd)
{
	t_list  *text;

	text = read_all(fd);
}

t_list  *read_all(int fd)
{
	t_list  *head;
	t_list  *node;
	char    *buffer;
	int     num_bytes;

	head = NULL;
	buffer == malloc(BUFFER_SIZE + 1);
	node = ft_lstnew(buffer);
	if (node == NULL || buffer == NULL)
	{
		free (node);
		free (buffer);
		return (NULL);
	}
	num_bytes = read(fd, node->content, BUFFER_SIZE);
	num_bytes = 1;
	while (num_bytes > 0)
	{
		buffer[num_bytes] = '\0';
		ft_lstadd_front(&head, node);
		buffer == malloc(BUFFER_SIZE + 1);
		node = ft_lstnew(buffer);
		if (node == NULL || buffer == NULL)
		{
			ft_lstclear(&head, free);
			free (node);
			free (buffer);
			return (NULL);
		}
		num_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	free (node);
	free (buffer);
	//Archivo ya no existe
	if (num_bytes == -1)
	{
		ft_lstclear(&head, free);
		free (NULL);
	}
	//El archivo estaba vacio
	if (head == NULL)
		return (NULL);
	return (head);
}
