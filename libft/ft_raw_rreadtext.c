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

void	ft_raw_rreadtext(int fd, t_list **head)
{
	t_list  *node;
	int     num_bytes;

	while (1)
	{
		node = ft_lstnew_s(malloc(BUFFER_SIZE + 1));
		if (node == NULL)
		{
			//perror("Memory allocation failed");
			ft_lstclear(head, free);
			return ;
		}
		num_bytes = read(fd, node->content, BUFFER_SIZE);
		if (num_bytes == -1 || num_bytes == 0) // Error reading file
		{
			ft_lstdelone(node, free);
			if (num_bytes == 0)
				return ;
			//perror("Error reading file");
			ft_lstclear(head, free);
			return ;
		}
		((char *) node->content)[num_bytes] = '\0'; // Null-terminate the string
		ft_lstadd_front(head, node);
	}
}
