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

#include "libft.h"

static int	ft_validateread(ssize_t num_bytes, t_list **head)
{
	if (num_bytes == -1)
	{
		ft_lstclear(head, free);
		return (READ_FAIL);
	}
	if (*head == NULL)
		return (READ_EMPTY);
	return (READ_SUCCESS);

}

int	ft_raw_rreadtext(int fd, t_list **head)
{
	t_list	*node;
	ssize_t	bytes_read;
	char	*read_buffer;

	*head = NULL;
	read_buffer = malloc(BUFFER_SIZE + 1);
	if (read_buffer == NULL)
			return (READ_FAIL_MALLOC);
	while (1)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE); 
		if (bytes_read == -1 || bytes_read == 0)
		{
			return (free(read_buffer), ft_validateread(bytes_read, head));
		}
		read_buffer[bytes_read] = '\0';
		node = ft_lstnew(ft_strdup(read_buffer));
		if (node == NULL || node->content == NULL)
		{
			ft_lstdelone(node, free);
			ft_lstclear(head, free);
			return (free(read_buffer), READ_FAIL_MALLOC);
		}
		ft_lstadd_front(head, node);
	}
}
